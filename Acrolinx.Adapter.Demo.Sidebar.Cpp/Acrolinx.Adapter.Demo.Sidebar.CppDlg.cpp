/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Adapter.Demo.Sidebar.CppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Acrolinx.Adapter.Demo.Sidebar.Cpp.h"
#include "Acrolinx.Adapter.Demo.Sidebar.CppDlg.h"
#include "afxdialogex.h"


// CAcrolinxAdapterDemoSidebarCppDlg dialog




CAcrolinxAdapterDemoSidebarCppDlg::CAcrolinxAdapterDemoSidebarCppDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CAcrolinxAdapterDemoSidebarCppDlg::IDD, pParent)
    , m_multiAdapterRequest(nullptr)
    , m_multiAdapterCurrent(nullptr)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAcrolinxAdapterDemoSidebarCppDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ACROLINXSIDEBAR1, m_sidebar);
    DDX_Control(pDX, IDC_TITLETXTBOX, m_titleTextBox);
    DDX_Control(pDX, IDC_DESCTXTBOX, m_descriptionTextBox);
    DDX_Control(pDX, IDC_XMLTXTBOX, m_contentTextBox);
}

BEGIN_MESSAGE_MAP(CAcrolinxAdapterDemoSidebarCppDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CAcrolinxAdapterDemoSidebarCppDlg message handlers

BOOL CAcrolinxAdapterDemoSidebarCppDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    m_titleTextBox.SetWindowTextW(L"TopSpin.xml");
    m_descriptionTextBox.SetWindowTextW(L"This is a sampple XML docunemt.");
    m_contentTextBox.SetWindowTextW(L"<x>\r\n    <some>Test</some>\r\n    <structured>data</structured>\r\n</x>");

    SetInitParameters();
    InitializeAdapters();
    m_sidebar.Start();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAcrolinxAdapterDemoSidebarCppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    CDialogEx::OnSysCommand(nID, lParam);

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAcrolinxAdapterDemoSidebarCppDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAcrolinxAdapterDemoSidebarCppDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}


void CAcrolinxAdapterDemoSidebarCppDlg::SetInitParameters(void)
{
    //m_sidebar.SetServerAddress(_T("http://yourlocalserver:8031"));
    //m_sidebar.SetShowServerSelector(FALSE);

    //Make sure to call m_sidebar.Start() instead of sidebar.StartWithServerAddress(serverAddress), if you uncomment one of these options.
    //m_sidebar.SetStartPageSourceLocation(_T("e:\\startpage\\Acrolinx.Startpage.dll"));

    //m_sidebar.SetClientSignature("ASK_ACROLINX_FOR_A_CLIENT_SIGNATURE");
    m_sidebar.SetClientSignature(_T("SW50ZWdyYXRpb25EZXZlbG9wbWVudERlbW9Pbmx5"));
    m_sidebar.SetSupportCheckSelection(true);

    /*
       To set language of sidebar same as of application uncomment following line and pass appropiate string (en, de, fr, sv, ja).
       Bydefault sidebar language is set same as user UI language for the current user. If the current user has not set a language, then the preferred language set for the system is used. 
       If there is no preferred language set for the system, then the system default UI language (also known as "install language") is used.
    */
    //m_sidebar.SetClientLocale(_T("en"));

    //Set version information. This is used for support and Acrolinx Analytics.
     m_sidebar.RegisterClientComponent(_T("com.adapter.acrolinx.demo.cpp"), _T("Acrolinx Sidebar Cpp Demo MultiSample"), _T("1.0.0.0"), CC_MAIN);
}

//Register the events you are interested in.
BEGIN_EVENTSINK_MAP(CAcrolinxAdapterDemoSidebarCppDlg, CDialogEx)
    ON_EVENT(CAcrolinxAdapterDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 3, CAcrolinxAdapterDemoSidebarCppDlg::RequestCheckAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxAdapterDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 5, CAcrolinxAdapterDemoSidebarCppDlg::SelectRangesAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxAdapterDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 6, CAcrolinxAdapterDemoSidebarCppDlg::ReplaceRangesAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxAdapterDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 4, CAcrolinxAdapterDemoSidebarCppDlg::CheckedAcrolinxsidebar1, VTS_DISPATCH)
END_EVENTSINK_MAP()


void CAcrolinxAdapterDemoSidebarCppDlg::RequestCheckAcrolinxsidebar1(LPDISPATCH checkOptions)
{
    m_multiAdapterRequest = new CMultiAdapter(_T("multisample.xml"), _T("CppMultiSampleDocument"), IF_XML);
    m_multiAdapterRequest->RegisterAdapter(&m_adapters);

    m_multiAdapterRequest->Extract();
    IDokumentPtr document = m_multiAdapterRequest->GetDocument();

    m_sidebar.Check(document);

}


void CAcrolinxAdapterDemoSidebarCppDlg::SelectRangesAcrolinxsidebar1(LPDISPATCH matches)
{
    IMatchesPtr matchesObj = nullptr;
    matches->QueryInterface(__uuidof(IMatches), (void**)&matchesObj);

    try
    {
        m_multiAdapterCurrent->SelectRanges(matchesObj);
    }
    catch (const std::runtime_error& ex)
    {
        m_sidebar.LogError(CString(ex.what()).AllocSysString());
        m_sidebar.InvalidateRanges(matches);
    }
    catch(...)
    {
        m_sidebar.LogError(_T("Selection failed"));
    }
}


void CAcrolinxAdapterDemoSidebarCppDlg::ReplaceRangesAcrolinxsidebar1(LPDISPATCH matches)
{
    IMatchesPtr matchesObj = nullptr;
    matches->QueryInterface(__uuidof(IMatches), (void**)&matchesObj);

    try
    {
        m_multiAdapterCurrent->ReplaceRanges(matchesObj);
    }
    catch (const std::runtime_error& ex)
    {
        m_sidebar.LogError(CString(ex.what()).AllocSysString());
        m_sidebar.InvalidateRanges(matches);
    }
    catch(...)
    {
        m_sidebar.LogError(_T("Replacement failed"));
    }
}


BOOL CAcrolinxAdapterDemoSidebarCppDlg::DestroyWindow()
{
    if(m_multiAdapterCurrent != NULL)
    {
        delete m_multiAdapterCurrent;
        m_multiAdapterCurrent = nullptr;
    }

    for(int i = 0 ; i < m_adapters.GetCount();i++)
    {
        delete m_adapters[i];
    }
    m_adapters.RemoveAll();

    return CDialogEx::DestroyWindow();
}


void CAcrolinxAdapterDemoSidebarCppDlg::InitializeAdapters(void)
{ 
    CUniversalAdapter* titleAdapter = new TextBoxAdapter(_T("title"), TRUE, m_titleTextBox);
    m_adapters.Add(titleAdapter);

    CUniversalAdapter* descriptionAdapter = new TextBoxAdapter(_T("description"), TRUE, m_descriptionTextBox);
    m_adapters.Add(descriptionAdapter);

    CUniversalAdapter* contentAdapter = new TextBoxAdapter(_T("xml"), FALSE, m_contentTextBox);
    m_adapters.Add(contentAdapter);
}


void CAcrolinxAdapterDemoSidebarCppDlg::CheckedAcrolinxsidebar1(LPDISPATCH checkResult)
{
    if(m_multiAdapterCurrent)
    {
        delete m_multiAdapterCurrent;
        m_multiAdapterCurrent = nullptr;
    }
    m_multiAdapterCurrent = m_multiAdapterRequest;
    m_multiAdapterRequest = nullptr;
}


BOOL CAcrolinxAdapterDemoSidebarCppDlg::PreTranslateMessage(MSG* pMsg)
{
    if( pMsg->message == WM_KEYDOWN )
    {
        if(pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
        {
            return TRUE;
        }
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}
