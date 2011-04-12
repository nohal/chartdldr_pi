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

#ifndef _WMMPI_H_
#define _WMMPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/fileconf.h>
#include <wx/tokenzr.h>
#include <wx/event.h>

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    1

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    4

#define     NOAA_CHART_SOURCES "NOAA ENC|http://www.charts.noaa.gov/ENCs/ENCProdCat.xml|.|NOAA RNC|http://www.charts.noaa.gov/RNCs/RNCProdCat.xml|."

#include "../../../include/ocpn_plugin.h"

#include "chartdldrgui.h"
#include "chartcatalog.h"

// forward declarations
class ChartSource;
WX_DECLARE_OBJARRAY(ChartSource *, wxArrayOfChartSources);

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define CHARTDLDR_TOOL_POSITION    -1          // Request default positioning of toolbar tool

class chartdldr_pi : public opencpn_plugin
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

//    The required override PlugIn Methods
      void ShowPreferencesDialog( wxWindow* parent );

//    Optional plugin overrides
      

//    Other public methods
      bool              SaveConfig(void);

//    Public properties
      wxArrayOfChartSources *m_chartSources;
      wxWindow         *m_parent_window;
      ChartCatalog     *m_pChartCatalog;
      ChartSource      *m_pChartSource;

private:
      wxFileConfig     *m_pconfig;
      bool              LoadConfig(void);

      int               m_leftclick_tool_id;
      bool              m_bChartDldrShowIcon;

      wxString          m_schartdldr_sources;
};

class ChartSource
{
public:
      ChartSource(wxString name, wxString url, wxString localdir);
      wxString GetName() { return m_name; }
      wxString GetUrl() { return m_url; }
      wxString GetDir() { return m_dir; }
      bool ExistsLocaly(wxString filename);
      bool IsNewerThanLocal(wxString filename);
private:
      wxArrayString GetLocalFiles();
      wxString m_name;
      wxString m_url;
      wxString m_dir;
};

/** Implementing ChartDldrPrefsDialog */
class ChartDldrPrefsDialogImpl : public ChartDldrPrefsDialog
{
protected:
      // Handlers for ChartDldrPrefsDialog events.
      void ShowHideToolbarIcon( wxCommandEvent& event ) { event.Skip(); }
	void OnSourceSelected( wxCommandEvent& event );
	void AddSource( wxCommandEvent& event );
	void DeleteSource( wxCommandEvent& event );
	void UpdateChartList( wxCommandEvent& event );
	void DownloadCharts( wxCommandEvent& event );
      
      void FillFromFile(wxString url, wxString dir);
public:
      ~ChartDldrPrefsDialogImpl();
      ChartDldrPrefsDialogImpl( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

      chartdldr_pi      *pPlugIn;
};

#endif
