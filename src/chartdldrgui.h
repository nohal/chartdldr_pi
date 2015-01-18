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
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/combobox.h>
#include "checkedlistctrl.h"
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AddSourceDlg
///////////////////////////////////////////////////////////////////////////////
class AddSourceDlg : public wxDialog 
{
	private:
	
	protected:
		wxRadioButton* m_radioBtn1;
		wxStaticText* m_staticText11;
		wxRadioButton* m_radioBtn2;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText4;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChangeType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSourceSelected( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxChoice* m_cbChartSources;
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
		wxListCtrl* m_lbChartSources;
		wxButton* m_bAddSource;
		wxButton* m_bDeleteSource;
		wxButton* m_bUpdateChartList;
		wxButton* m_bDnldCharts;
		
		// Virtual event handlers, overide them in your derived class
		virtual void SelectSource( wxListEvent& event ) { event.Skip(); }
		virtual void AddSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdateChartList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnContextMenu( wxMouseEvent& event ) { event.Skip(); }
		virtual void DownloadCharts( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxCheckedListCtrl *m_clCharts;
		
		ChartDldrPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
		~ChartDldrPanel();
	
};

#endif //__chartdldrgui__
