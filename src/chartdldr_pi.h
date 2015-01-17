/******************************************************************************
 * $Id: chartdldr_pi.h,v 1.0 2011/02/26 01:54:37 nohal Exp $
 *
 * Project:  OpenCPN
 * Purpose:  Chart Downloader Plugin
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

#ifndef _CHARTDLDRPI_H_
#define _CHARTDLDRPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/fileconf.h>
#include <wx/tokenzr.h>
#include <wx/event.h>
#include "wx/curl/dialog.h"

#include "version.h"

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    9

#define     NOAA_CHART_SOURCES "NOAA ENC - all charts - (too) big!|http://www.charts.noaa.gov/ENCs/ENCProdCat.xml|.|\
NOAA RNC - all charts - (too) big!|http://www.charts.noaa.gov/RNCs/RNCProdCat.xml|.|\
USACE IENC charts|http://crunch.tec.army.mil/enc/echarts/catalog/iencproductscatalog.xml|.|\
NOAA RNC AK|http://www.charts.noaa.gov/RNCs/AK_RNCProdCat.xml|.|\
NOAA RNC AL|http://www.charts.noaa.gov/RNCs/AL_RNCProdCat.xml|.|\
NOAA RNC CA|http://www.charts.noaa.gov/RNCs/CA_RNCProdCat.xml|.|\
NOAA RNC CT|http://www.charts.noaa.gov/RNCs/CT_RNCProdCat.xml|.|\
NOAA RNC DE|http://www.charts.noaa.gov/RNCs/DE_RNCProdCat.xml|.|\
NOAA RNC FL|http://www.charts.noaa.gov/RNCs/FL_RNCProdCat.xml|.|\
NOAA RNC GA|http://www.charts.noaa.gov/RNCs/GA_RNCProdCat.xml|.|\
NOAA RNC HI|http://www.charts.noaa.gov/RNCs/HI_RNCProdCat.xml|.|\
NOAA RNC ID|http://www.charts.noaa.gov/RNCs/ID_RNCProdCat.xml|.|\
NOAA RNC IL|http://www.charts.noaa.gov/RNCs/IL_RNCProdCat.xml|.|\
NOAA RNC IN|http://www.charts.noaa.gov/RNCs/IN_RNCProdCat.xml|.|\
NOAA RNC LA|http://www.charts.noaa.gov/RNCs/LA_RNCProdCat.xml|.|\
NOAA RNC MA|http://www.charts.noaa.gov/RNCs/MA_RNCProdCat.xml|.|\
NOAA RNC MD|http://www.charts.noaa.gov/RNCs/MD_RNCProdCat.xml|.|\
NOAA RNC ME|http://www.charts.noaa.gov/RNCs/ME_RNCProdCat.xml|.|\
NOAA RNC MI|http://www.charts.noaa.gov/RNCs/MI_RNCProdCat.xml|.|\
NOAA RNC MN|http://www.charts.noaa.gov/RNCs/MN_RNCProdCat.xml|.|\
NOAA RNC MS|http://www.charts.noaa.gov/RNCs/MS_RNCProdCat.xml|.|\
NOAA RNC NC|http://www.charts.noaa.gov/RNCs/NC_RNCProdCat.xml|.|\
NOAA RNC NH|http://www.charts.noaa.gov/RNCs/NH_RNCProdCat.xml|.|\
NOAA RNC NJ|http://www.charts.noaa.gov/RNCs/NJ_RNCProdCat.xml|.|\
NOAA RNC NV|http://www.charts.noaa.gov/RNCs/NV_RNCProdCat.xml|.|\
NOAA RNC NY|http://www.charts.noaa.gov/RNCs/NY_RNCProdCat.xml|.|\
NOAA RNC OH|http://www.charts.noaa.gov/RNCs/OH_RNCProdCat.xml|.|\
NOAA RNC OR|http://www.charts.noaa.gov/RNCs/OR_RNCProdCat.xml|.|\
NOAA RNC PA|http://www.charts.noaa.gov/RNCs/PA_RNCProdCat.xml|.|\
NOAA RNC PO (Pacific ocean)|http://www.charts.noaa.gov/RNCs/PO_RNCProdCat.xml|.|\
NOAA RNC PR|http://www.charts.noaa.gov/RNCs/PR_RNCProdCat.xml|.|\
NOAA RNC RI|http://www.charts.noaa.gov/RNCs/RI_RNCProdCat.xml|.|\
NOAA RNC SC|http://www.charts.noaa.gov/RNCs/SC_RNCProdCat.xml|.|\
NOAA RNC TX|http://www.charts.noaa.gov/RNCs/TX_RNCProdCat.xml|.|\
NOAA RNC VA|http://www.charts.noaa.gov/RNCs/VA_RNCProdCat.xml|.|\
NOAA RNC VT|http://www.charts.noaa.gov/RNCs/VT_RNCProdCat.xml|.|\
NOAA RNC WA|http://www.charts.noaa.gov/RNCs/WA_RNCProdCat.xml|.|\
NOAA RNC WI|http://www.charts.noaa.gov/RNCs/WI_RNCProdCat.xml|.|\
NOAA ENC AK|http://www.charts.noaa.gov/ENCs/AK_ENCProdCat.xml|.|\
NOAA ENC AL|http://www.charts.noaa.gov/ENCs/AL_ENCProdCat.xml|.|\
NOAA ENC CA|http://www.charts.noaa.gov/ENCs/CA_ENCProdCat.xml|.|\
NOAA ENC CT|http://www.charts.noaa.gov/ENCs/CT_ENCProdCat.xml|.|\
NOAA ENC DE|http://www.charts.noaa.gov/ENCs/DE_ENCProdCat.xml|.|\
NOAA ENC FL|http://www.charts.noaa.gov/ENCs/FL_ENCProdCat.xml|.|\
NOAA ENC GA|http://www.charts.noaa.gov/ENCs/GA_ENCProdCat.xml|.|\
NOAA ENC HI|http://www.charts.noaa.gov/ENCs/HI_ENCProdCat.xml|.|\
NOAA ENC ID|http://www.charts.noaa.gov/ENCs/ID_ENCProdCat.xml|.|\
NOAA ENC IL|http://www.charts.noaa.gov/ENCs/IL_ENCProdCat.xml|.|\
NOAA ENC IN|http://www.charts.noaa.gov/ENCs/IN_ENCProdCat.xml|.|\
NOAA ENC LA|http://www.charts.noaa.gov/ENCs/LA_ENCProdCat.xml|.|\
NOAA ENC MA|http://www.charts.noaa.gov/ENCs/MA_ENCProdCat.xml|.|\
NOAA ENC MD|http://www.charts.noaa.gov/ENCs/MD_ENCProdCat.xml|.|\
NOAA ENC ME|http://www.charts.noaa.gov/ENCs/ME_ENCProdCat.xml|.|\
NOAA ENC MI|http://www.charts.noaa.gov/ENCs/MI_ENCProdCat.xml|.|\
NOAA ENC MN|http://www.charts.noaa.gov/ENCs/MN_ENCProdCat.xml|.|\
NOAA ENC MS|http://www.charts.noaa.gov/ENCs/MS_ENCProdCat.xml|.|\
NOAA ENC NC|http://www.charts.noaa.gov/ENCs/NC_ENCProdCat.xml|.|\
NOAA ENC NH|http://www.charts.noaa.gov/ENCs/NH_ENCProdCat.xml|.|\
NOAA ENC NJ|http://www.charts.noaa.gov/ENCs/NJ_ENCProdCat.xml|.|\
NOAA ENC NY|http://www.charts.noaa.gov/ENCs/NY_ENCProdCat.xml|.|\
NOAA ENC OH|http://www.charts.noaa.gov/ENCs/OH_ENCProdCat.xml|.|\
NOAA ENC OR|http://www.charts.noaa.gov/ENCs/OR_ENCProdCat.xml|.|\
NOAA ENC PA|http://www.charts.noaa.gov/ENCs/PA_ENCProdCat.xml|.|\
NOAA ENC PO (Pacific ocean)|http://www.charts.noaa.gov/ENCs/PO_ENCProdCat.xml|.|\
NOAA ENC PR|http://www.charts.noaa.gov/ENCs/PR_ENCProdCat.xml|.|\
NOAA ENC RI|http://www.charts.noaa.gov/ENCs/RI_ENCProdCat.xml|.|\
NOAA ENC SC|http://www.charts.noaa.gov/ENCs/SC_ENCProdCat.xml|.|\
NOAA ENC TX|http://www.charts.noaa.gov/ENCs/TX_ENCProdCat.xml|.|\
NOAA ENC VA|http://www.charts.noaa.gov/ENCs/VA_ENCProdCat.xml|.|\
NOAA ENC WA|http://www.charts.noaa.gov/ENCs/WA_ENCProdCat.xml|.|\
NOAA ENC WI|http://www.charts.noaa.gov/ENCs/WI_ENCProdCat.xml|.|"

#include "ocpn_plugin.h"

#include "chartdldrgui.h"
#include "chartcatalog.h"

// forward declarations
class ChartSource;
class ChartDldrPanelImpl;
class ChartDldrGuiAddSourceDlg;

WX_DECLARE_OBJARRAY(ChartSource *, wxArrayOfChartSources);

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

class chartdldr_pi : public opencpn_plugin_19
{
public:
      chartdldr_pi(void *ppimgr);

//    The required PlugIn Methods
      int Init(void);
      bool DeInit(void);

      int GetAPIVersionMajor();
      int GetAPIVersionMinor();
      int GetPlugInVersionMajor();
      int GetPlugInVersionMinor();
      wxBitmap *GetPlugInBitmap();
      wxString GetCommonName();
      wxString GetShortDescription();
      wxString GetLongDescription();

      void OnSetupOptions(void);
      void OnCloseToolboxPanel(int page_sel, int ok_apply_cancel);

//    The required override PlugIn Methods
      void ShowPreferencesDialog( wxWindow* parent );

//    Other public methods
      bool              SaveConfig(void);
      bool              ExtractZipFiles(const wxString& aZipFile, const wxString& aTargetDir, bool aStripPath = true, wxDateTime aMTime = wxDateTime::Now());

//    Public properties
      wxArrayOfChartSources *m_chartSources;
      wxWindow         *m_parent_window;
      ChartCatalog     *m_pChartCatalog;
      ChartSource      *m_pChartSource;
      void              SetSourceId(int id) { m_selected_source = id; }
      int               GetSourceId() { return m_selected_source; }

private:
      wxFileConfig     *m_pconfig;
      wxScrolledWindow *m_pOptionsPage;
      bool              LoadConfig(void);

      int               m_leftclick_tool_id;

      wxString          m_schartdldr_sources;
      int               m_selected_source;
      
      ChartDldrPanelImpl *m_dldrpanel;
};

class ChartSource
{
public:
      ChartSource(wxString name, wxString url, wxString localdir);
      wxString GetName() { return m_name; }
      wxString GetUrl() { return m_url; }
      wxString GetDir() { return m_dir; }
      void SetDir(wxString dir) { m_dir = dir; }
      bool ExistsLocaly(wxString filename);
      bool IsNewerThanLocal(wxString filename, wxDateTime validDate);
      void UpdateLocalFiles() { m_localfiles = GetLocalFiles(); }
private:
      wxArrayString m_localfiles;
      wxArrayString GetLocalFiles();
      wxString m_name;
      wxString m_url;
      wxString m_dir;
};

/** Implementing ChartDldrPanel */
class ChartDldrPanelImpl : public ChartDldrPanel
{
friend class chartdldr_pi;
private:
    bool DownloadChart(wxString url, wxString file);
    bool downloadInProgress;
    int to_download;
    int downloading;
    bool cancelled;
    chartdldr_pi      *pPlugIn;

    void OnPopupClick(wxCommandEvent &evt);

protected:
      // Handlers for ChartDldrPanel events.
    void SetSource(int id);
	void SelectSource( wxCommandEvent& event );
	void AddSource( wxCommandEvent& event );
	void DeleteSource( wxCommandEvent& event );
	void UpdateChartList( wxCommandEvent& event );
	void DownloadCharts( wxCommandEvent& event );
    void OnLocalDirChanged( wxFileDirPickerEvent& event );
      
    void CleanForm();
    void FillFromFile(wxString url, wxString dir, bool selnew = false, bool selupd = false);

    void OnContextMenu( wxMouseEvent& event );

public:
    ~ChartDldrPanelImpl();
    ChartDldrPanelImpl( chartdldr_pi* plugin, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
};

class ChartDldrGuiAddSourceDlg : public AddSourceDlg
{
	protected:
        wxArrayOfChartSources *m_chartSources;
		void OnChangeType( wxCommandEvent& event );
		void OnSourceSelected( wxCommandEvent& event );

	public:
		ChartDldrGuiAddSourceDlg( wxWindow* parent );
		~ChartDldrGuiAddSourceDlg();

};

#endif
