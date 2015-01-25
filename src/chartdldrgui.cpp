///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "chartdldrgui.h"

///////////////////////////////////////////////////////////////////////////

AddSourceDlg::AddSourceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerSourceSel;
	sbSizerSourceSel = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Catalog") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerSourceSel;
	fgSizerSourceSel = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizerSourceSel->AddGrowableCol( 2 );
	fgSizerSourceSel->SetFlexibleDirection( wxBOTH );
	fgSizerSourceSel->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_rbPredefined = new wxRadioButton( this, wxID_ANY, _("Predefined"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerSourceSel->Add( m_rbPredefined, 0, wxALL|wxEXPAND, 5 );
	
	m_stCatalog = new wxStaticText( this, wxID_ANY, _("Catalog"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stCatalog->Wrap( -1 );
	fgSizerSourceSel->Add( m_stCatalog, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_cbChartSourcesChoices;
	m_cbChartSources = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cbChartSourcesChoices, 0 );
	m_cbChartSources->SetSelection( 0 );
	fgSizerSourceSel->Add( m_cbChartSources, 0, wxALL|wxEXPAND, 5 );
	
	m_rbCustom = new wxRadioButton( this, wxID_ANY, _("Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerSourceSel->Add( m_rbCustom, 0, wxALL, 5 );
	
	m_stName = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stName->Wrap( -1 );
	fgSizerSourceSel->Add( m_stName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_tSourceName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_tSourceName->SetMaxLength( 0 ); 
	m_tSourceName->Enable( false );
	
	fgSizerSourceSel->Add( m_tSourceName, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerSourceSel->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_stUrl = new wxStaticText( this, wxID_ANY, _("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stUrl->Wrap( -1 );
	fgSizerSourceSel->Add( m_stUrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_tChartSourceUrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_tChartSourceUrl->SetMaxLength( 0 ); 
	m_tChartSourceUrl->Enable( false );
	
	fgSizerSourceSel->Add( m_tChartSourceUrl, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizerSourceSel->Add( fgSizerSourceSel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( sbSizerSourceSel, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerChartDir;
	bSizerChartDir = new wxBoxSizer( wxHORIZONTAL );
	
	m_stChartDir = new wxStaticText( this, wxID_ANY, _("Chart directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stChartDir->Wrap( -1 );
	bSizerChartDir->Add( m_stChartDir, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_dpChartDirectory = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL );
	bSizerChartDir->Add( m_dpChartDirectory, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( bSizerChartDir, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerBtns = new wxStdDialogButtonSizer();
	m_sdbSizerBtnsOK = new wxButton( this, wxID_OK );
	m_sdbSizerBtns->AddButton( m_sdbSizerBtnsOK );
	m_sdbSizerBtnsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerBtns->AddButton( m_sdbSizerBtnsCancel );
	m_sdbSizerBtns->Realize();
	
	bSizerMain->Add( m_sdbSizerBtns, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_rbPredefined->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	m_cbChartSources->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddSourceDlg::OnSourceSelected ), NULL, this );
	m_rbCustom->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	m_sdbSizerBtnsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddSourceDlg::OnOkClick ), NULL, this );
}

AddSourceDlg::~AddSourceDlg()
{
	// Disconnect Events
	m_rbPredefined->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	m_cbChartSources->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddSourceDlg::OnSourceSelected ), NULL, this );
	m_rbCustom->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( AddSourceDlg::OnChangeType ), NULL, this );
	m_sdbSizerBtnsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddSourceDlg::OnOkClick ), NULL, this );
	
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
	
	m_lbChartSources = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer4->Add( m_lbChartSources, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_bAddSource = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_bAddSource->SetToolTip( _("Add a new chart catalog.") );
	
	bSizer8->Add( m_bAddSource, 0, wxALL|wxEXPAND, 5 );
	
	m_bDeleteSource = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bDeleteSource->SetToolTip( _("Delete the chart catalog. The downloaded charts are not deleted.") );
	
	bSizer8->Add( m_bDeleteSource, 0, wxALL|wxEXPAND, 5 );
	
	m_bUpdateChartList = new wxButton( this, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bUpdateChartList->SetDefault(); 
	m_bUpdateChartList->SetToolTip( _("Download the current chart catalog and update the data.") );
	
	bSizer8->Add( m_bUpdateChartList, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer8, 0, wxEXPAND, 5 );
	
	
	sbSchartsource->Add( bSizer4, 1, wxEXPAND, 0 );
	
	
	bSizer1->Add( sbSchartsource, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSCharts;
	sbSCharts = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Charts") ), wxVERTICAL );
	
	sbSCharts->SetMinSize( wxSize( -1,350 ) ); 
	m_clCharts = new wxCheckedListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL);
	//m_clCharts>SetImagesForList(wxLC_REPORT|wxLC_SINGLE_SEL);
	//m_clCharts>UpdateStyle();
	sbSCharts->Add( m_clCharts, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBtns;
	bSizerBtns = new wxBoxSizer( wxHORIZONTAL );
	
	m_bDnldCharts = new wxButton( this, wxID_ANY, _("Download selected charts"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bDnldCharts->SetDefault(); 
	bSizerBtns->Add( m_bDnldCharts, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_bShowLocal = new wxButton( this, wxID_ANY, _("Show local files"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBtns->Add( m_bShowLocal, 0, wxALL, 5 );
	
	
	sbSCharts->Add( bSizerBtns, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSCharts, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_lbChartSources->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( ChartDldrPanel::SelectSource ), NULL, this );
	m_bAddSource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::AddSource ), NULL, this );
	m_bDeleteSource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DeleteSource ), NULL, this );
	m_bUpdateChartList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::UpdateChartList ), NULL, this );
	m_clCharts->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( ChartDldrPanel::OnContextMenu ), NULL, this );
	m_bDnldCharts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DownloadCharts ), NULL, this );
	m_bShowLocal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::OnShowLocalDir ), NULL, this );
}

ChartDldrPanel::~ChartDldrPanel()
{
	// Disconnect Events
	m_lbChartSources->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( ChartDldrPanel::SelectSource ), NULL, this );
	m_bAddSource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::AddSource ), NULL, this );
	m_bDeleteSource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DeleteSource ), NULL, this );
	m_bUpdateChartList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::UpdateChartList ), NULL, this );
	m_clCharts->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( ChartDldrPanel::OnContextMenu ), NULL, this );
	m_bDnldCharts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::DownloadCharts ), NULL, this );
	m_bShowLocal->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPanel::OnShowLocalDir ), NULL, this );
	
}

ChartDldrPrefsDlg::ChartDldrPrefsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerPrefsMain;
	bSizerPrefsMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerPaths;
	sbSizerPaths = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Default Path to Charts") ), wxVERTICAL );
	
	m_dpDefaultDir = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a root folder for your charts"), wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL );
	sbSizerPaths->Add( m_dpDefaultDir, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerPrefsMain->Add( sbSizerPaths, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerBehavior;
	sbSizerBehavior = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Preferences") ), wxVERTICAL );
	
	m_stPreselect = new wxStaticText( this, wxID_ANY, _("After catalog update select for download"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stPreselect->Wrap( -1 );
	sbSizerBehavior->Add( m_stPreselect, 0, wxALL, 5 );
	
	m_cbSelectUpdated = new wxCheckBox( this, wxID_ANY, _("All updated charts"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbSelectUpdated->SetValue(true); 
	sbSizerBehavior->Add( m_cbSelectUpdated, 0, wxALL, 5 );
	
	m_cbSelectNew = new wxCheckBox( this, wxID_ANY, _("All new charts"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerBehavior->Add( m_cbSelectNew, 0, wxALL, 5 );
	
	
	bSizerPrefsMain->Add( sbSizerBehavior, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerBtns = new wxStdDialogButtonSizer();
	m_sdbSizerBtnsOK = new wxButton( this, wxID_OK );
	m_sdbSizerBtns->AddButton( m_sdbSizerBtnsOK );
	m_sdbSizerBtnsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerBtns->AddButton( m_sdbSizerBtnsCancel );
	m_sdbSizerBtns->Realize();
	
	bSizerPrefsMain->Add( m_sdbSizerBtns, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPrefsMain );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sdbSizerBtnsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDlg::OnCancelClick ), NULL, this );
	m_sdbSizerBtnsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDlg::OnOkClick ), NULL, this );
}

ChartDldrPrefsDlg::~ChartDldrPrefsDlg()
{
	// Disconnect Events
	m_sdbSizerBtnsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDlg::OnCancelClick ), NULL, this );
	m_sdbSizerBtnsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartDldrPrefsDlg::OnOkClick ), NULL, this );
	
}
