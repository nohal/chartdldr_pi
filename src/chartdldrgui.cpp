///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "chartdldrgui.h"

///////////////////////////////////////////////////////////////////////////

ChartDldrPrefsDialog::ChartDldrPrefsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	bSizer1->SetMinSize( wxSize( 500,-1 ) ); 
	m_cbShowToolbarIcon = new wxCheckBox( this, wxID_ANY, _("Show in Toolbar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_cbShowToolbarIcon, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSchartsource;
	sbSchartsource = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Charts source") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Chart source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	wxArrayString m_cbChartSourcesChoices;
	m_cbChartSources = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cbChartSourcesChoices, 0 );
	m_cbChartSources->SetSelection( 0 );
	fgSizer1->Add( m_cbChartSources, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	m_tChartSourceUrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_READONLY );
	fgSizer1->Add( m_tChartSourceUrl, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Chart directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALL, 5 );
	
	m_dpChartDirectory = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	fgSizer1->Add( m_dpChartDirectory, 0, wxALL|wxEXPAND, 5 );
	
	sbSchartsource->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bAddSource = new wxButton( this, wxID_ANY, _("Add new source"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer4->Add( m_bAddSource, 0, wxALL, 5 );
	
	m_bDeleteSource = new wxButton( this, wxID_ANY, _("Delete source"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_bDeleteSource, 0, wxALL, 5 );
	
	m_bUpdateChartList = new wxButton( this, wxID_ANY, _("Update chart list"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bUpdateChartList->SetDefault(); 
	bSizer4->Add( m_bUpdateChartList, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	sbSchartsource->Add( bSizer4, 1, wxEXPAND, 0 );
	
	bSizer1->Add( sbSchartsource, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSSourceInfo;
	sbSSourceInfo = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Chart source info") ), wxVERTICAL );
	
	m_tChartSourceInfo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER );
	sbSSourceInfo->Add( m_tChartSourceInfo, 0, wxALL|wxEXPAND, 5 );
	
	bSizer1->Add( sbSSourceInfo, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSCharts;
	sbSCharts = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Charts") ), wxVERTICAL );
	
	sbSCharts->SetMinSize( wxSize( -1,250 ) ); 
	m_clCharts = new wxCheckedListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL);
	//m_clCharts>SetImagesForList(wxLC_REPORT|wxLC_SINGLE_SEL);
	//m_clCharts>UpdateStyle();
	sbSCharts->Add( m_clCharts, 1, wxALL|wxEXPAND, 5 );
	
	m_bDnldCharts = new wxButton( this, wxID_ANY, _("Download selected charts"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSCharts->Add( m_bDnldCharts, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer1->Add( sbSCharts, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	bSizer1->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_cbShowToolbarIcon->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::ShowHideToolbarIcon ), NULL, this );
	m_cbChartSources->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ChartDldrPrefsDialog::OnSourceSelected ), NULL, this );
	m_dpChartDirectory->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( ChartDldrPrefsDialog::OnLocalDirChanged ), NULL, this );
	m_bAddSource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::AddSource ), NULL, this );
	m_bDeleteSource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::DeleteSource ), NULL, this );
	m_bUpdateChartList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::UpdateChartList ), NULL, this );
	m_bDnldCharts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::DownloadCharts ), NULL, this );
}

ChartDldrPrefsDialog::~ChartDldrPrefsDialog()
{
	// Disconnect Events
	m_cbShowToolbarIcon->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::ShowHideToolbarIcon ), NULL, this );
	m_cbChartSources->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ChartDldrPrefsDialog::OnSourceSelected ), NULL, this );
	m_dpChartDirectory->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( ChartDldrPrefsDialog::OnLocalDirChanged ), NULL, this );
	m_bAddSource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::AddSource ), NULL, this );
	m_bDeleteSource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::DeleteSource ), NULL, this );
	m_bUpdateChartList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::UpdateChartList ), NULL, this );
	m_bDnldCharts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDialog::DownloadCharts ), NULL, this );
	
}

DlProgressDialog::DlProgressDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Download progress") ), wxVERTICAL );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Total"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	sbSizer3->Add( m_staticText5, 0, wxALL, 5 );
	
	m_gTotalProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	sbSizer3->Add( m_gTotalProgress, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, _("Current chart"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	sbSizer3->Add( m_staticText6, 0, wxALL, 5 );
	
	m_gChartProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	sbSizer3->Add( m_gChartProgress, 0, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( sbSizer3, 1, wxEXPAND|wxFIXED_MINSIZE, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
	m_sdbSizer2->Realize();
	bSizer2->Add( m_sdbSizer2, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

DlProgressDialog::~DlProgressDialog()
{
}

AddSourceDlg::AddSourceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1->SetMinSize( wxSize( 500,-1 ) ); 
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Chart source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	m_tSourceName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_tSourceName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	m_tChartSourceUrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	fgSizer1->Add( m_tChartSourceUrl, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Chart directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALL, 5 );
	
	m_dpChartDirectory = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	fgSizer1->Add( m_dpChartDirectory, 0, wxALL|wxEXPAND, 5 );
	
	bSizer3->Add( fgSizer1, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	bSizer3->Add( m_sdbSizer3, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	bSizer3->Fit( this );
	
	this->Centre( wxBOTH );
}

AddSourceDlg::~AddSourceDlg()
{
}
