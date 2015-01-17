/******************************************************************************
 * $Id: chartdldr_pi.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
 *
 * Project:  OpenCPN
 * Purpose:  Chart downloader Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2011 by Pavel Kalian   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "chartdldr_pi.h"
#include <wx/url.h>
#include <wx/progdlg.h>
#include <wx/sstream.h>
#include <wx/wfstream.h>
#include <wx/filename.h>
#include <wx/listctrl.h>
#include <wx/dir.h>
#include <wx/filesys.h>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <memory>
#include <wx/protocol/http.h>

#include <wx/arrimpl.cpp>
    WX_DEFINE_OBJARRAY(wxArrayOfChartSources);


// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new chartdldr_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//event table
IMPLEMENT_CLASS(ChartDldrPanelImpl, ChartDldrPanel)
BEGIN_EVENT_TABLE(ChartDldrPanelImpl, ChartDldrPanel)
      EVT_HTTPBUILDER_FINISHED(wxID_ANY, ChartDldrPanelImpl::OnDownloadComplete)
      EVT_TIMER(wxID_ANY, ChartDldrPanelImpl::OnTimer)
END_EVENT_TABLE()

//---------------------------------------------------------------------------------------------------------
//
//    ChartDldr PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

chartdldr_pi::chartdldr_pi(void *ppimgr)
      :opencpn_plugin_19(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();

      m_chartSources = NULL;
      m_parent_window = NULL;
      m_pChartCatalog = NULL;
      m_pChartSource = NULL;
      m_pconfig = NULL;
      m_leftclick_tool_id = -1;
      m_schartdldr_sources = wxEmptyString;
}

int chartdldr_pi::Init(void)
{
      AddLocaleCatalog( _T("opencpn-chartdldr_pi") );

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();
      m_pOptionsPage = NULL;

      m_chartSources = new wxArrayOfChartSources();
      m_pChartCatalog = new ChartCatalog;
      m_pChartSource = NULL;

      //    And load the configuration items
      LoadConfig();

      wxStringTokenizer st(m_schartdldr_sources, _T("|"), wxTOKEN_DEFAULT);
      while ( st.HasMoreTokens() )
      {
            wxString s1 = st.GetNextToken();
            wxString s2 = st.GetNextToken();
            wxString s3 = st.GetNextToken();
            m_chartSources->Add(new ChartSource(s1, s2, s3));
      }

      return (
              WANTS_PREFERENCES         |
              WANTS_CONFIG              |
              INSTALLS_TOOLBOX_PAGE
           );
}

bool chartdldr_pi::DeInit(void)
{
      m_chartSources->Clear();
      wxDELETE(m_chartSources);
      wxDELETE(m_pChartCatalog);
      wxDELETE(m_pChartSource);
      /* TODO: Seth */
//      dialog->Close();
//      dialog->Destroy();
//      wxDELETE(dialog);
      /* We must delete remaining page if the plugin is disabled while in Options dialog */
      if ( m_pOptionsPage )
      {
            if ( DeleteOptionsPage( m_pOptionsPage ) )
                  m_pOptionsPage = NULL;
            // TODO: any other memory leak?
      }
      return true;
}

int chartdldr_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int chartdldr_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int chartdldr_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int chartdldr_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *chartdldr_pi::GetPlugInBitmap()
{
      return _img_chartdldr_pi;
}

wxString chartdldr_pi::GetCommonName()
{
      return _("ChartDownloader");
}


wxString chartdldr_pi::GetShortDescription()
{
      return _("Chart Downloader PlugIn for OpenCPN");
}

wxString chartdldr_pi::GetLongDescription()
{
      return _("Chart Downloader PlugIn for OpenCPN\n\
Manages chart downloads and updates from sources supporting\n\
NOAA Chart Catalog format");
}

void chartdldr_pi::OnSetupOptions(void)
{
      m_pOptionsPage = AddOptionsPage( PI_OPTIONS_PARENT_CHARTS, _("Chart Downloader") );
      if (! m_pOptionsPage) {
            wxLogMessage( _T("Error: chartdldr_pi::OnSetupOptions AddOptionsPage failed!") );
            return;
      }
      wxBoxSizer *sizer = new wxBoxSizer( wxVERTICAL );
      m_pOptionsPage->SetSizer( sizer );

      /* TODO: Seth */
      ChartDldrPanelImpl *dialog = new ChartDldrPanelImpl( m_pOptionsPage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->pPlugIn = this;

      for (size_t i = 0; i < m_chartSources->GetCount(); i++)
      {
            ((wxItemContainer*)dialog->m_cbChartSources)->Append(m_chartSources->Item(i)->GetName());
      }

      sizer->Add( dialog, 0, wxALL | wxEXPAND );
}

void chartdldr_pi::OnCloseToolboxPanel(int page_sel, int ok_apply_cancel)
{
      /* TODO: Seth */
      SaveConfig();
}

bool chartdldr_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/ChartDnldr" ) );
            pConf->Read ( _T ( "Sources" ), &m_schartdldr_sources, _T(NOAA_CHART_SOURCES) );
            return true;
      }
      else
            return false;
}

bool chartdldr_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      m_schartdldr_sources.Clear();

      for (size_t i = 0; i < m_chartSources->GetCount(); i++)
      {
            m_schartdldr_sources.Append(wxString::Format(_T("%s|%s|%s|"), m_chartSources->Item(i)->GetName().c_str(), m_chartSources->Item(i)->GetUrl().c_str(), m_chartSources->Item(i)->GetDir().c_str()));
      }

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/ChartDnldr" ) );
            pConf->Write ( _T ( "Sources" ), m_schartdldr_sources );

            return true;
      }
      else
            return false;
}

void chartdldr_pi::ShowPreferencesDialog( wxWindow* parent )
{
}

ChartSource::ChartSource(wxString name, wxString url, wxString localdir)
{
      m_name = name;
      m_url = url;
      m_dir = localdir;
}

#define ID_MNU_SELALL 2001
#define ID_MNU_DELALL 2002
#define ID_MNU_INVSEL 2003
#define ID_MNU_SELUPD 2004
#define ID_MNU_SELNEW 2005

void ChartDldrPanelImpl::OnPopupClick(wxCommandEvent &evt)
{
	switch(evt.GetId()) {
		case ID_MNU_SELALL:
                  m_clCharts->CheckAll(true);
			break;
		case ID_MNU_DELALL:
                  m_clCharts->CheckAll(false);
			break;
            case ID_MNU_INVSEL:
                  for (int i = 0; i < m_clCharts->GetItemCount(); i++)
                        m_clCharts->Check(i, !m_clCharts->IsChecked(i));
			break;
            case ID_MNU_SELUPD:
			FillFromFile(pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection())->GetUrl(), pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection())->GetDir(), false, true);
                  break;
            case ID_MNU_SELNEW:
                  FillFromFile(pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection())->GetUrl(), pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection())->GetDir(), true, false);
			break;
	}
}

void ChartDldrPanelImpl::OnContextMenu( wxMouseEvent& event )
{
      if (m_clCharts->GetItemCount() == 0)
            return;
      wxMenu menu;
      wxPoint point = event.GetPosition();
      wxPoint p1 = ((wxWindow *)m_clCharts)->GetPosition();

      // add stuff
      menu.Append(ID_MNU_SELALL, _("Select all"), wxT(""));
      menu.Append(ID_MNU_DELALL, _("Deselect all"), wxT(""));
      menu.Append(ID_MNU_INVSEL, _("Invert selection"), wxT(""));
      menu.Append(ID_MNU_SELUPD, _("Select updated"), wxT(""));
      menu.Append(ID_MNU_SELNEW, _("Select new"), wxT(""));
      menu.Connect(wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ChartDldrPanelImpl::OnPopupClick, NULL, this);
      // and then display
      PopupMenu(&menu, p1.x + point.x, p1.y + point.y);
}

void ChartDldrPanelImpl::OnTimer( wxTimerEvent &event )
{
      if( m_http )
      {
            wxMutexLocker lock(m_mutexHTTPObj);
            if (dialog)
                  dialog->m_sBytesRead->SetLabel(wxString::Format(_("Downloaded: %i bytes"), m_http->GetBytesRead()));
      }
      else
      {
            if(dialog)
                  dialog->m_sBytesRead->SetLabel(_("Downloaded: N/A"));
      }
}

void ChartDldrPanelImpl::OnDownloadComplete(wxHTTPBuilderEvent &)
{
      m_thread = NULL;

      wxMutexLocker lock( m_mutexHTTPObj);

      if( m_http )
            delete m_http;
      m_http = NULL;

      //unpack
      dialog->m_sBytesRead->SetLabel(_("Extracting archive..."));
      wxFileName fn(localfiles[downloading - 1]);
      pPlugIn->ExtractZipFiles(localfiles[downloading - 1], fn.GetPath(), true, filetimes[downloading - 1]);
      wxRemoveFile(localfiles[downloading - 1]);

      downloadInProgress = false;

      if (!cancelled && downloading != to_download)
      {
            if (dialog)
                  DownloadChart(urls[downloading], localfiles[downloading]);
      }
      else
      {
            this->Enable();
            if(dialog)
            {
                  dialog->Close();
                  dialog->Destroy();
            }
            wxDELETE(dialog);
            m_timer->Stop();
            wxDELETE(m_timer);
            m_timer = NULL;
            cancelled = false;
            ChartSource *cs = pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection());
            CleanForm();
            FillFromFile(cs->GetUrl(), cs->GetDir());
      }
}

void ChartDldrPanelImpl::OnSourceSelected( wxCommandEvent& event )
{
      ChartSource *cs = pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection());
      m_tChartSourceUrl->SetValue(cs->GetUrl());
      m_dpChartDirectory->SetPath(cs->GetDir());

      pPlugIn->m_pChartSource = cs;
      CleanForm();
      FillFromFile(cs->GetUrl(), cs->GetDir());

      event.Skip();
}

void ChartDldrPanelImpl::CleanForm()
{
      m_tChartSourceInfo->SetValue(wxEmptyString);
      m_clCharts->DeleteAllItems();
}

void ChartDldrPanelImpl::FillFromFile(wxString url, wxString dir, bool selnew, bool selupd)
{
      //load if exists
      wxStringTokenizer tk(url, _T("/"));
      wxString file;
      do
      {
            file = tk.GetNextToken();
      } while(tk.HasMoreTokens());
      wxFileName fn;
      fn.SetFullName(file);
      fn.SetPath(dir);
      wxString path = fn.GetFullPath();
      if (wxFileExists(path))
      {
            pPlugIn->m_pChartCatalog->LoadFromFile(path);
            m_tChartSourceInfo->SetValue(pPlugIn->m_pChartCatalog->GetDescription());
            //fill in the rest of the form
            m_clCharts->DeleteAllItems();
            for(size_t i = 0; i < pPlugIn->m_pChartCatalog->charts->Count(); i++)
            {
                  wxListItem li;
                  li.SetId(i);
                  li.SetText(pPlugIn->m_pChartCatalog->charts->Item(i).GetChartTitle());
                  long x = m_clCharts->InsertItem(li);
                  m_clCharts->SetItem(x, 0, pPlugIn->m_pChartCatalog->charts->Item(i).GetChartTitle());
                  wxString file = pPlugIn->m_pChartCatalog->charts->Item(i).GetChartFilename();
                  if (!pPlugIn->m_pChartSource->ExistsLocaly(file))
                  {
                        m_clCharts->SetItem(x, 1, _("New"));
                        if (selnew)
                              m_clCharts->Check(x, true);
                  }
                  else
                  {
                        if(pPlugIn->m_pChartSource->IsNewerThanLocal(file, pPlugIn->m_pChartCatalog->charts->Item(i).GetUpdateDatetime()))
                        {
                              m_clCharts->SetItem(x, 1, _("Update available"));
                              if (selupd)
                                    m_clCharts->Check(x, true);
                        }
                        else
                        {
                              m_clCharts->SetItem(x, 1, _("Up to date"));
                        }
                  }
            }
      }
}

bool ChartSource::ExistsLocaly(wxString filename)
{
      wxArrayString lf = GetLocalFiles();
      wxStringTokenizer tk(filename, _T("."));
      wxString file = tk.GetNextToken();
      for (size_t i = 0; i < lf.Count(); i++)
      {
            wxFileName fn(lf.Item(i));
            if(fn.GetName().StartsWith(file))
                  return true;
      }
      return false;
}

bool ChartSource::IsNewerThanLocal(wxString filename, wxDateTime validDate)
{
      wxArrayString lf = GetLocalFiles();
      wxStringTokenizer tk(filename, _T("."));
      wxString file = tk.GetNextToken();
      for (size_t i = 0; i < lf.Count(); i++)
      {
            wxFileName fn(lf.Item(i));
            if(fn.GetName().StartsWith(file))
            {
                  wxDateTime ct, mt, at;
                  fn.GetTimes(&at, &mt, &ct);
                  if (validDate.IsLaterThan(ct))
                        return true;
            }
      }
      return false;
}

void ChartDldrPanelImpl::UpdateChartList( wxCommandEvent& event )
{
      //TODO: check if everything exists and we can write to the output dir etc.
      if (m_cbChartSources->GetSelection() < 0)
            return;
      ChartSource *cs = pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection());
      wxURL * url = new wxURL(cs->GetUrl());
      if (url->GetError() != wxURL_NOERR)
      {
            wxMessageBox(_("Error, the URL to the chart source data seems wrong."), _("Error"));
            wxDELETE(url);
            return;
      }
      wxInputStream *in_stream;
      in_stream = url->GetInputStream();
      wxString res;
      int done = 0;
      if (url->GetError() == wxPROTO_NOERR)
      {
            wxProgressDialog prog(_("Downloading..."), _("Downloading chart list..."), in_stream->GetSize() + 1);
            prog.Show();
            wxStringOutputStream out_stream(&res);
            char * buffer = new char[8192];
            size_t read;
            do
            {
                  in_stream->Read(buffer, 8191);
                  read = in_stream->LastRead();
                  out_stream.Write(buffer, read);
                  done += read;
                  prog.Update(done);

            } while (!in_stream->Eof());
            delete[] buffer;
      }
      else
      {
            wxMessageBox(_("Unable to connect."), _("Error"));
            wxDELETE(in_stream);
            wxDELETE(url);
            return;
      }
      //save
      wxStringTokenizer tk(url->GetPath(), _T("/"));
      wxString file;
      do
      {
            file = tk.GetNextToken();
      } while(tk.HasMoreTokens());
      wxFileName fn;
      fn.SetFullName(file);
      fn.SetPath(m_dpChartDirectory->GetPath());
      wxString path = fn.GetFullPath();
      if (wxFileExists(path))
            wxRemoveFile(path);
      wxTextFile txt(path);
      txt.Create();
      txt.AddLine(res);
      txt.Write();
      txt.Close();
      FillFromFile(url->GetPath(), fn.GetPath());
      //clean up
      wxDELETE(in_stream);
      wxDELETE(url);
}

wxArrayString ChartSource::GetLocalFiles()
{
      wxArrayString *ret = new wxArrayString();
      wxDir::GetAllFiles(GetDir(), ret);
      wxArrayString r(*ret);
      wxDELETE(ret);
      return r;
}

void ChartDldrPanelImpl::DownloadChart(wxString url, wxString file)
{
      if (cancelled)
            return;
      dialog->m_gTotalProgress->SetValue(downloading);
      dialog->m_sCurrentChart->SetLabel(wxString::Format(_("Downloading: %s"), url.c_str()));
      downloading++;

      downloadInProgress = true;
      m_http = new wxHTTPBuilder();
      m_http->InitContentTypes(); // Initialise the content types on the page

      m_thread = new wxHTTPBuilderThread(this, wxID_ANY, m_http, url);
      m_thread->SaveToFile(true, file);
      if( m_thread->Create() != wxTHREAD_NO_ERROR )
      {
		m_thread = NULL;
            delete m_http;
            m_http = NULL;
            downloadInProgress = false;
      }
      else
      {
            m_thread->Run();
      }
}

void ChartDldrPanelImpl::DownloadCharts( wxCommandEvent& event )
{
      urls.Clear();
      localfiles.Clear();
      filetimes.Clear();
      if (m_clCharts->GetCheckedItemCount() == 0)
            return;
      to_download = m_clCharts->GetCheckedItemCount();
      downloading = 0;
      dialog = new DlProgressDialogImpl(this);
      dialog->pParent = this;
      dialog->m_gTotalProgress->SetRange(to_download);
      dialog->Show();
      this->Disable();
      for (int i = 0; i < m_clCharts->GetItemCount(); i++)
      {
            //Prepare download queues
            if(m_clCharts->IsChecked(i))
            {
                  //download queue
                  filetimes.Add(pPlugIn->m_pChartCatalog->charts->Item(i).GetUpdateDatetime());
                  wxURL * url = new wxURL(pPlugIn->m_pChartCatalog->charts->Item(i).GetDownloadLocation());
                  if (url->GetError() != wxURL_NOERR)
                  {
                        wxMessageBox(_("Error, the URL to the chart data seems wrong."), _("Error"));
                        wxDELETE(url);
                        this->Enable();
                        dialog->Close();
                        dialog->Destroy();
                        wxDELETE(dialog);
                        return;
                  }
                  wxHTTPBuilder http;
                  http.InitContentTypes();
                  wxString sUrl = url->GetURL();
                  dialog->m_sCurrentChart->SetLabel(wxString::Format(_("Checking for redirect: %s"), sUrl.c_str()));
                  wxInputStream *in_stream;
                  in_stream = http.GetInputStream(sUrl);
                  int RetCode = http.GetResponse();
                  if (RetCode > 300 && RetCode < 400) //Redirect - will not work if more than one...
                  {
                        sUrl = http.GetHeader(wxT("Location"));
                        dialog->m_sCurrentChart->SetLabel(wxString::Format(_("Detected redirect to: %s"), sUrl.c_str()));
                  }
                  http.Close();
                  wxDELETE(in_stream);
                  urls.Add(sUrl);
                  //construct local zipfile path
                  wxString file = pPlugIn->m_pChartCatalog->charts->Item(i).GetChartFilename();
                  wxFileName fn;
                  fn.SetFullName(file);
                  fn.SetPath(m_dpChartDirectory->GetPath());
                  wxString path = fn.GetFullPath();
                  if (wxFileExists(path))
                        wxRemoveFile(path);
                  localfiles.Add(path);
            }
      }
      m_timer = new wxTimer(this, wxID_ANY);
      m_timer->Start( 500, FALSE ); // Fire every 1/2 second
      DownloadChart(urls[downloading], localfiles[downloading]);
}

void ChartDldrPanelImpl::OnLocalDirChanged( wxFileDirPickerEvent& event )
{
      pPlugIn->m_chartSources->Item(m_cbChartSources->GetSelection())->SetDir(m_dpChartDirectory->GetPath());
      pPlugIn->SaveConfig();
      event.Skip();
}

ChartDldrPanelImpl::~ChartDldrPanelImpl()
{
      ((wxListCtrl *)m_clCharts)->DeleteAllItems();
      if (m_timer)
            m_timer->Stop();
      wxDELETE(m_timer);
      m_timer = NULL;
}

ChartDldrPanelImpl::ChartDldrPanelImpl( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
            : ChartDldrPanel( parent, id, pos, size, style )
{
      // Add columns
      wxListItem col0;
      col0.SetId(0);
      col0.SetText( _("Title") );
      col0.SetWidth(200);
      ((wxListCtrl *)m_clCharts)->InsertColumn(0, col0);
      wxListItem col1;
      col1.SetId(1);
      col1.SetText( _("Status") );
      col1.SetWidth(100);
      ((wxListCtrl *)m_clCharts)->InsertColumn(1, col1);

      m_thread = NULL;
      m_http = NULL;
      m_timer = NULL;
      downloadInProgress = false;
      cancelled = false;
      dialog = NULL;
      to_download = -1;
      downloading = -1;
      pPlugIn = NULL;
}

void ChartDldrPanelImpl::DeleteSource( wxCommandEvent& event )
{
      pPlugIn->m_chartSources->RemoveAt(m_cbChartSources->GetSelection());
      ((wxItemContainer*)m_cbChartSources)->Delete(m_cbChartSources->GetSelection());
      m_cbChartSources->Select(-1);
      m_tChartSourceUrl->SetValue(wxEmptyString);
      m_dpChartDirectory->SetPath(wxEmptyString);
      pPlugIn->SaveConfig();
      event.Skip();
}

void ChartDldrPanelImpl::AddSource( wxCommandEvent& event )
{
      AddSourceDlg *dialog = new AddSourceDlg(pPlugIn->m_parent_window);
      if(dialog->ShowModal() == wxID_OK)
      {
            pPlugIn->m_chartSources->Add(new ChartSource(dialog->m_tSourceName->GetValue(), dialog->m_tChartSourceUrl->GetValue(), dialog->m_dpChartDirectory->GetPath()));
            ((wxItemContainer*)m_cbChartSources)->Append(dialog->m_tSourceName->GetValue());
            /*m_cbChartSources->Select(m_cbChartSources->GetChildren().GetCount() - 1);
            m_tChartSourceUrl->SetValue(dialog->m_tChartSourceUrl->GetValue());
            m_dpChartDirectory->SetPath(dialog->m_dpChartDirectory->GetPath());*/
            pPlugIn->SaveConfig();
      }
      dialog->Close();
      dialog->Destroy();
      wxDELETE(dialog);
      event.Skip();
}

bool chartdldr_pi::ExtractZipFiles(const wxString& aZipFile, const wxString& aTargetDir, bool aStripPath, wxDateTime aMTime) {
      bool ret = true;

      std::auto_ptr<wxZipEntry> entry(new wxZipEntry());

      do {

            wxFileInputStream in(aZipFile);

            if (!in) {
                  wxLogError(_T("Can not open file '")+aZipFile+_T("'."));
                  ret = false;
                  break;
            }
            wxZipInputStream zip(in);

            while (entry.reset(zip.GetNextEntry()), entry.get() != NULL) {
                  // access meta-data
                  wxString name = entry->GetName();
                  name = aTargetDir + wxFileName::GetPathSeparator() + name;

                  // read 'zip' to access the entry's data
                  if (entry->IsDir()) {
                        int perm = entry->GetMode();
                        wxFileName::Mkdir(name, perm, wxPATH_MKDIR_FULL);
                  } else {
                        zip.OpenEntry(*entry.get());
                        if (!zip.CanRead()) {
                              wxLogError(_T("Can not read zip entry '") + entry->GetName() + _T("'."));
                              ret = false;
                              break;
                        }

                        wxFileName fn(name);
                        if (aStripPath)
                        {
                              fn.SetPath(aTargetDir);
                              name = fn.GetFullPath();
                        }

                        wxFileOutputStream file(name);

                        if (!file) {
                              wxLogError(_T("Can not create file '")+name+_T("'."));
                              ret = false;
                              break;
                        }
                        zip.Read(file);
                        wxString s = aMTime.Format();
                        fn.SetTimes(&aMTime, &aMTime, &aMTime);
                  }

            }

      } while(false);

      return ret;
}

void ChartDldrPanelImpl::CancelDownload()
{
      m_timer->Stop();
      m_http->Stop();
      cancelled = true;
      Enable();
}

void DlProgressDialogImpl::CancelDownload( wxCommandEvent& event )
{
      pParent->CancelDownload();
      event.Skip();
}
