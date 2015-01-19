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

#define     NOAA_CHART_SOURCES "US RNC Region 02 - Block Island, RI to the Canadian Border|http://www.charts.noaa.gov/RNCs/02Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION02|\
US RNC Region 03 - New York to Nantucket and Cape May, NJ|http://www.charts.noaa.gov/RNCs/03Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION03|\
US RNC Region 04 - Chesapeake and Delaware Bays|http://www.charts.noaa.gov/RNCs/04Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION04|\
US RNC Region 06 - Norfolk, VA to Florida including the ICW|http://www.charts.noaa.gov/RNCs/06Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION06|\
US RNC Region 07 - Florida East Coast and the Keys|http://www.charts.noaa.gov/RNCs/07Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION07|\
US RNC Region 08 - Florida West Coast and the Keys|http://www.charts.noaa.gov/RNCs/08Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION08|\
US RNC Region 10 - Puerto Rico and the U.S. Virgin Islands|http://www.charts.noaa.gov/RNCs/10Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION10|\
US RNC Region 12 - Southern California: Point Arena to the Mexican Border|http://www.charts.noaa.gov/RNCs/12Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION12|\
US RNC Region 13 - Lake Michigan|http://www.charts.noaa.gov/RNCs/13Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION13|\
US RNC Region 14 - San Francisco to Cape Flattery|http://www.charts.noaa.gov/RNCs/14Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION14|\
US RNC Region 15 - Pacific Northwest: Puget Sound to the Canadian Border|http://www.charts.noaa.gov/RNCs/15Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION15|\
US RNC Region 17 - Mobile, AL to the Mexican Border|http://www.charts.noaa.gov/RNCs/17Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION17|\
US RNC Region 22 - Lake Superior and Lake Huron (U.S. Waters)|http://www.charts.noaa.gov/RNCs/22Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION22|\
US RNC Region 24 - Lake Erie (U.S. Waters)|http://www.charts.noaa.gov/RNCs/24Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION24|\
US RNC Region 26 - Lake Ontario (U.S. Waters)|http://www.charts.noaa.gov/RNCs/26Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION26|\
US RNC Region 30 - Southeast Alaska|http://www.charts.noaa.gov/RNCs/30Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION30|\
US RNC Region 32 - South Central Alaska: Yakutat to Kodiak|http://www.charts.noaa.gov/RNCs/32Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION32|\
US RNC Region 34 - Alaska: The Aleutians and Bristol Bay|http://www.charts.noaa.gov/RNCs/34Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION34|\
US RNC Region 36 - Alaska: Norton Sound to Beaufort Sea|http://www.charts.noaa.gov/RNCs/36Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION36|\
US RNC Region 40 - Hawaiian Islands and U.S. Territories|http://www.charts.noaa.gov/RNCs/40Region_RNCProdCat.xml|{USERDATA}/{Charts}/RNC/US_REGION40|\
US ENC Region 02 - Block Island, RI to the Canadian Border|http://www.charts.noaa.gov/ENCs/02Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION02|\
US ENC Region 03 - New York to Nantucket and Cape May, NJ|http://www.charts.noaa.gov/ENCs/03Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION03|\
US ENC Region 04 - Chesapeake and Delaware Bays|http://www.charts.noaa.gov/ENCs/04Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION04|\
US ENC Region 06 - Norfolk, VA to Florida including the ICW|http://www.charts.noaa.gov/ENCs/06Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION06|\
US ENC Region 07 - Florida East Coast and the Keys|http://www.charts.noaa.gov/ENCs/07Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION07|\
US ENC Region 08 - Florida West Coast and the Keys|http://www.charts.noaa.gov/ENCs/08Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION08|\
US ENC Region 10 - Puerto Rico and the U.S. Virgin Islands|http://www.charts.noaa.gov/ENCs/10Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION10|\
US ENC Region 12 - Southern California: Point Arena to the Mexican Border|http://www.charts.noaa.gov/ENCs/12Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION12|\
US ENC Region 13 - Lake Michigan|http://www.charts.noaa.gov/ENCs/13Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION13|\
US ENC Region 14 - San Francisco to Cape Flattery|http://www.charts.noaa.gov/ENCs/14Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION14|\
US ENC Region 15 - Pacific Northwest: Puget Sound to the Canadian Border|http://www.charts.noaa.gov/ENCs/15Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION15|\
US ENC Region 17 - Mobile, AL to the Mexican Border|http://www.charts.noaa.gov/ENCs/17Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION17|\
US ENC Region 22 - Lake Superior and Lake Huron (U.S. Waters)|http://www.charts.noaa.gov/ENCs/22Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION22|\
US ENC Region 24 - Lake Erie (U.S. Waters)|http://www.charts.noaa.gov/ENCs/24Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION24|\
US ENC Region 26 - Lake Ontario (U.S. Waters)|http://www.charts.noaa.gov/ENCs/26Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION26|\
US ENC Region 30 - Southeast Alaska|http://www.charts.noaa.gov/ENCs/30Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION30|\
US ENC Region 32 - South Central Alaska: Yakutat to Kodiak|http://www.charts.noaa.gov/ENCs/32Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION32|\
US ENC Region 34 - Alaska: The Aleutians and Bristol Bay|http://www.charts.noaa.gov/ENCs/34Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION34|\
US ENC Region 36 - Alaska: Norton Sound to Beaufort Sea|http://www.charts.noaa.gov/ENCs/36Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION36|\
US ENC Region 40 - Hawaiian Islands and U.S. Territories|http://www.charts.noaa.gov/ENCs/40Region_ENCProdCat.xml|{USERDATA}/{Charts}/ENC/US_REGION40|\
US ACE Inland ENC charts|http://inland.agc.army.mil/enc/echarts/catalog/iencu37productscatalog.xml|{USERDATA}/{Charts}/ENC/US_INLAND|"

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
    bool DownloadChart(wxString url, wxString file, wxString title);
    bool downloadInProgress;
    int to_download;
    int downloading;
    bool cancelled;
    chartdldr_pi      *pPlugIn;

    void OnPopupClick(wxCommandEvent &evt);
    int GetSelectedCatalog();
    void AppendCatalog(ChartSource *cs);

protected:
      // Handlers for ChartDldrPanel events.
    void SetSource(int id);
	void SelectSource( wxListEvent& event );
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
    void SelectCatalog(int item);
};

class ChartDldrGuiAddSourceDlg : public AddSourceDlg
{
	protected:
        wxArrayOfChartSources *m_chartSources;
		void OnChangeType( wxCommandEvent& event );
		void OnSourceSelected( wxCommandEvent& event );
		void OnOkClick( wxCommandEvent& event );

	public:
		ChartDldrGuiAddSourceDlg( wxWindow* parent );
		~ChartDldrGuiAddSourceDlg();

};

#endif
