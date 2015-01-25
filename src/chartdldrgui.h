///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CHARTDLDRGUI_H__
#define __CHARTDLDRGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/combobox.h>
#include "checkedlistctrl.h"
#include <wx/panel.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AddSourceDlg
///////////////////////////////////////////////////////////////////////////////
class AddSourceDlg : public wxDialog 
{
	private:
	
	protected:
		wxRadioButton* m_rbPredefined;
		wxRadioButton* m_rbCustom;
		wxStaticText* m_stCatalog;
		wxStaticText* m_stName;
		wxStaticText* m_stUrl;
		wxStdDialogButtonSizer* m_sdbSizerBtns;
		wxButton* m_sdbSizerBtnsOK;
		wxButton* m_sdbSizerBtnsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChangeType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSourceSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
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
		wxButton* m_bEditSource;
		wxButton* m_bUpdateChartList;
		wxButton* m_bDnldCharts;
		wxButton* m_bShowLocal;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void SelectSource( wxListEvent& event ) { event.Skip(); }
		virtual void AddSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void EditSource( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdateChartList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnContextMenu( wxMouseEvent& event ) { event.Skip(); }
		virtual void DownloadCharts( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowLocalDir( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxCheckedListCtrl *m_clCharts;
		
		ChartDldrPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~ChartDldrPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChartDldrPrefsDlg
///////////////////////////////////////////////////////////////////////////////
class ChartDldrPrefsDlg : public wxDialog 
{
	private:
	
	protected:
		wxDirPickerCtrl* m_dpDefaultDir;
		wxStaticText* m_stPreselect;
		wxCheckBox* m_cbSelectUpdated;
		wxCheckBox* m_cbSelectNew;
		wxStdDialogButtonSizer* m_sdbSizerBtns;
		wxButton* m_sdbSizerBtnsOK;
		wxButton* m_sdbSizerBtnsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ChartDldrPrefsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Chart Downloader Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 462,331 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ChartDldrPrefsDlg();
	
};

#endif //__CHARTDLDRGUI_H__
