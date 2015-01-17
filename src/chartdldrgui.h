///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __chartdldrgui__
#define __chartdldrgui__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/gauge.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include "checkedlistctrl.h"
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DlProgressDialog
///////////////////////////////////////////////////////////////////////////////
class DlProgressDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText5;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CancelDownload( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxGauge* m_gTotalProgress;
		wxStaticText* m_sCurrentChart;
		wxStaticText* m_sBytesRead;
		
		DlProgressDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Download progress"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,-1 ), long style = wxCAPTION );
		~DlProgressDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddSourceDlg
///////////////////////////////////////////////////////////////////////////////
class AddSourceDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText4;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
	
	public:
		wxTextCtrl* m_tSourceName;
		wxTextCtrl* m_tChartSourceUrl;
		wxDirPickerCtrl* m_dpChartDirectory;
		
		AddSourceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New chart source"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~AddSourceDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChartDldrPanel
///////////////////////////////////////////////////////////////////////////////
class ChartDldrPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText4;
		wxButton* m_bAddSource;
		wxButton* m_bDeleteSource;
		wxButton* m_bUpdateChartList;
		wxTextCtrl* m_tChartSourceInfo;
		wxButton* m_bDnldCharts;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSourceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLocalDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void AddSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdateChartList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnContextMenu( wxMouseEvent& event ) { event.Skip(); }
		virtual void DownloadCharts( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxChoice* m_cbChartSources;
		wxTextCtrl* m_tChartSourceUrl;
		wxDirPickerCtrl* m_dpChartDirectory;
		wxCheckedListCtrl *m_clCharts;
		
		ChartDldrPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
		~ChartDldrPanel();
	
};

#endif //__chartdldrgui__
