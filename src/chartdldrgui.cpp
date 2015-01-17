///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "chartdldrgui.h"

///////////////////////////////////////////////////////////////////////////

AddSourceDlg::AddSourceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Catalog") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer1->AddGrowableCol( 2 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1->SetMinSize( wxSize( 500,-1 ) ); 
	m_radioBtn1 = new wxRadioButton( this, wxID_ANY, _("Existing"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_radioBtn1, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Catalog"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer1->Add( m_staticText11, 0, wxALL, 5 );
	
	wxArrayString m_cbChartSourcesChoices;
	m_cbChartSources = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cbChartSourcesChoices, 0 );
	m_cbChartSources->SetSelection( 0 );
	fgSizer1->Add( m_cbChartSources, 0, wxALL|wxEXPAND, 5 );
	
	m_radioBtn2 = new wxRadioButton( this, wxID_ANY, _("Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_radioBtn2, 0, wxALL, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	m_tSourceName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_tSourceName->Enable( false );
	
	fgSizer1->Add( m_tSourceName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer1->Add( m_staticText10, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	m_tChartSourceUrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_tChartSourceUrl->Enable( false );
	
	fgSizer1->Add( m_tChartSourceUrl, 0, wxALL|wxEXPAND, 5 );
	
	sbSizer5->Add( fgSizer1, 0, wxALL, 5 );
	
	bSizer3->Add( sbSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Chart directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer6->Add( m_staticText4, 0, wxALL|wxEXPAND, 5 );
	
	m_dpChartDirectory = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL );
	bSizer6->Add( m_dpChartDirectory, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer3->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );
	
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
	
	// Connect Events
	m_radioBtn1->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	m_cbChartSources->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddSourceDlg::OnSourceSelected ), NULL, this );
	m_radioBtn2->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
}

AddSourceDlg::~AddSourceDlg()
{
	// Disconnect Events
	m_radioBtn1->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	m_cbChartSources->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddSourceDlg::OnSourceSelected ), NULL, this );
	m_radioBtn2->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	
}

ChartDldrPanel::ChartDldrPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	bSizer1->SetMinSize( wxSize( 500,-1 ) ); 
	wxStaticBoxSizer* sbSchartsource;
	sbSchartsource = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Catalogs") ), wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lbChartSources = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer4->Add( m_lbChartSources, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_bAddSource = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer8->Add( m_bAddSource, 0, wxALL|wxEXPAND, 5 );
	
	m_bDeleteSource = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_bDeleteSource, 0, wxALL|wxEXPAND, 5 );
	
	m_bUpdateChartList = new wxButton( this, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bUpdateChartList->SetDefault(); 
	bSizer8->Add( m_bUpdateChartList, 0, wxALL|wxEXPAND, 5 );
	
	bSizer4->Add( bSizer8, 0, wxEXPAND, 5 );
	
	sbSchartsource->Add( bSizer4, 1, wxEXPAND, 0 );
	
	bSizer1->Add( sbSchartsource, 0, wxALL|wxEXPAND, 5 );
	
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
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_lbChartSources->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ChartDldrPanel::SelectSource ), NULL, this );
	m_bAddSource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::AddSource ), NULL, this );
	m_bDeleteSource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DeleteSource ), NULL, this );
	m_bUpdateChartList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::UpdateChartList ), NULL, this );
	m_clCharts->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( ChartDldrPanel::OnContextMenu ), NULL, this );
	m_bDnldCharts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DownloadCharts ), NULL, this );
}

ChartDldrPanel::~ChartDldrPanel()
{
	// Disconnect Events
	m_lbChartSources->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ChartDldrPanel::SelectSource ), NULL, this );
	m_bAddSource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::AddSource ), NULL, this );
	m_bDeleteSource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DeleteSource ), NULL, this );
	m_bUpdateChartList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::UpdateChartList ), NULL, this );
	m_clCharts->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( ChartDldrPanel::OnContextMenu ), NULL, this );
	m_bDnldCharts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DownloadCharts ), NULL, this );
	
}
