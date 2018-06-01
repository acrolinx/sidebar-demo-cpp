/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Demo.Sidebar.CppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Acrolinx.Demo.Sidebar.Cpp.h"
#include "Acrolinx.Demo.Sidebar.CppDlg.h"
#include "afxdialogex.h"


// CAcrolinxDemoSidebarCppDlg dialog

CAcrolinxDemoSidebarCppDlg::CAcrolinxDemoSidebarCppDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CAcrolinxDemoSidebarCppDlg::IDD, pParent)
    , m_documentModelCurrent(nullptr)
    , m_documentModelRequest(nullptr)
    , m_minimumSize(0,0)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAcrolinxDemoSidebarCppDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ACROLINXSIDEBAR1, m_sidebar);
    DDX_Control(pDX, IDC_TEXTBOX, m_textbox);
    DDX_Control(pDX, IDC_FORMATCOMBOBOX, m_format);
}

BEGIN_MESSAGE_MAP(CAcrolinxDemoSidebarCppDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_GETMINMAXINFO()
    ON_WM_SIZE()
END_MESSAGE_MAP()


// CAcrolinxDemoSidebarCppDlg message handlers

BOOL CAcrolinxDemoSidebarCppDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    InitializeResizer();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    //Set default text in Edit Control
    m_textbox.SetWindowTextW(L"This texxt contains intentional errorrs.\r\nAnother kine containning mistakas.");
    m_format.SetCurSel(2);

    //Set combo box read-only
    CEdit* comboBoxEditControl = (CEdit*)m_format.GetWindow(GW_CHILD);
    comboBoxEditControl->SetReadOnly();

    RegisterControlForAutoSizing(IDC_ACROLINXSIDEBAR1, 0, 0, 100, 100);
    RegisterControlForAutoSizing(IDC_DOCREFTEXTBOX, 0, 0, 100, 0);
    RegisterControlForAutoSizing(IDC_TEXTBOX, 0, 0, 0, 100);

    // Initialize Acrolinx Sidebar
    SetInitParameters();
    m_sidebar.Start();


    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAcrolinxDemoSidebarCppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    CDialogEx::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAcrolinxDemoSidebarCppDlg::OnPaint()
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
HCURSOR CAcrolinxDemoSidebarCppDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CAcrolinxDemoSidebarCppDlg::SetInitParameters(void)
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
    //m_sidebar.RegisterClientComponent(_T("com.acrolinx.demo.cpp"), _T("Acrolinx Sidebar Cpp Demo"), _T("1.0.0.1"), CC_MAIN);
}

//Register the events you are interested in.
BEGIN_EVENTSINK_MAP(CAcrolinxDemoSidebarCppDlg, CDialogEx)
    ON_EVENT(CAcrolinxDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 2, CAcrolinxDemoSidebarCppDlg::InitFinishedAcrolinxsidebar1, VTS_NONE)
    ON_EVENT(CAcrolinxDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 3, CAcrolinxDemoSidebarCppDlg::RequestCheckAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 5, CAcrolinxDemoSidebarCppDlg::SelectRangesAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 6, CAcrolinxDemoSidebarCppDlg::ReplaceRangesAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 4, CAcrolinxDemoSidebarCppDlg::CheckedAcrolinxsidebar1, VTS_DISPATCH)
    ON_EVENT(CAcrolinxDemoSidebarCppDlg, IDC_ACROLINXSIDEBAR1, 1, CAcrolinxDemoSidebarCppDlg::SidebarLoadedAcrolinxsidebar1, VTS_BSTR)
END_EVENTSINK_MAP()


void CAcrolinxDemoSidebarCppDlg::InitFinishedAcrolinxsidebar1()
{
    m_sidebar.LogInfo(L"Sidebar intialized");
}


void CAcrolinxDemoSidebarCppDlg::RequestCheckAcrolinxsidebar1(LPDISPATCH checkOptions)
{
    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(OLESTR("ACROSIDEBAR.DocumentModel.1"), &clsid);
    hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,
    __uuidof(IDocumentModel), (void **)&m_documentModelRequest);

    ICheckOptionsPtr checkOptionsInstance = nullptr;
    checkOptions->QueryInterface(__uuidof(ICheckOptions), (void**)&checkOptionsInstance);

    IDispatchPtr documentDispatch = nullptr;
    documentDispatch = m_sidebar.CreateDocument();

    IDokumentPtr documentInstance = nullptr;
    documentDispatch->QueryInterface(__uuidof(IDokument), (void**)&documentInstance);

    CString content =  GetDialogText(IDC_TEXTBOX);
    CString docReference = GetDialogText(IDC_DOCREFTEXTBOX);
    CString inputFormat = GetDialogText(IDC_FORMATCOMBOBOX);
    Input_Format format = GetFormatFromString(inputFormat);

    IDispatchPtr rangeListDispatch = nullptr;
    rangeListDispatch = m_sidebar.CreateRangeList();

    IRangesPtr rangeListInstance= nullptr;
    rangeListDispatch->QueryInterface(__uuidof(IRanges), (void**)&rangeListInstance);

    int startPos = 0, endPos = 0;
    m_textbox.GetSel(startPos, endPos);
    if(endPos > startPos)
    {
        rangeListInstance->AddRange(startPos, endPos);
    }

    documentInstance->InitInstanceWithSelectionRanges(content.AllocSysString(), docReference.AllocSysString(), format, rangeListInstance);

    m_documentModelRequest->InitInstance(content.AllocSysString());

    m_sidebar.Check(documentInstance);


    //Release the created document
    documentDispatch->Release();
}


CString CAcrolinxDemoSidebarCppDlg::GetDialogText(int dialogID)
{
    CString content;
    GetDlgItemTextW(dialogID, content);
    return content;
}


void CAcrolinxDemoSidebarCppDlg::SelectRangesAcrolinxsidebar1(LPDISPATCH matches)
{
    IMatchesPtr matchesObj = nullptr;
    matches->QueryInterface(__uuidof(IMatches), (void**)&matchesObj);

    LONG matchCount = 0;
    matchesObj->GetMatchCount(&matchCount);

    IMatchPtr startMatch = nullptr, endMatch = nullptr;
    matchesObj->GetMatchAt(0, &startMatch);

    matchesObj->GetMatchAt(matchCount - 1, &endMatch);

    IRangePtr startRange = nullptr, endRange = nullptr;

    startMatch->GetRange(&startRange);
    endMatch->GetRange(&endRange);

    IRangePtr relativeStartRange = nullptr, relativeEndRange = nullptr;
    HRESULT hRes = m_documentModelCurrent->GetOriginalToCurrentRange(startRange, &relativeStartRange);
    if(hRes == S_OK)
    {
        hRes = m_documentModelCurrent->GetOriginalToCurrentRange(endRange, &relativeEndRange);
        if(hRes == S_OK)
        {
            LONG orgStartOffset = 0, orgEndOffset = 0;
            startRange->GetStart(&orgStartOffset);
            endRange->GetEnd(&orgEndOffset);
            BSTR content;
            m_documentModelCurrent->GetOrginalContent(&content);

            CString matchContent(content);
            matchContent = matchContent.Mid(orgStartOffset, orgEndOffset - orgStartOffset);

            LONG startOffset = 0, endOffset = 0;
            relativeStartRange->GetStart(&startOffset);
            relativeEndRange->GetEnd(&endOffset);

            m_textbox.SetSel(startOffset,endOffset);
        }
        else
        {
            m_sidebar.InvalidateRanges(matches);
        }
    }
    else
    {
        m_sidebar.InvalidateRanges(matches);
    }
}


void CAcrolinxDemoSidebarCppDlg::ReplaceRangesAcrolinxsidebar1(LPDISPATCH matches)
{
    IMatchesPtr matchesObj = nullptr;
    matches->QueryInterface(__uuidof(IMatches), (void**)&matchesObj);

    LONG matchCount = 0;
    matchesObj->GetMatchCount(&matchCount);

    for(int idx = matchCount - 1; idx >= 0; idx --)
    {
        IMatchPtr match = nullptr;
        matchesObj->GetMatchAt(idx, &match);

        IRangePtr range = nullptr;
        match->GetRange(&range);

        IRangePtr relativeRange = nullptr;
        if(S_OK == m_documentModelCurrent->GetOriginalToCurrentRange(range, &relativeRange))
        {
            LONG startOffset = 0, endOffset = 0;
            relativeRange->GetStart(&startOffset);
            relativeRange->GetEnd(&endOffset);
            m_textbox.SetSel(startOffset,endOffset);

            BSTR replacement;
            match->GetMatchReplacement(&replacement);
            m_textbox.ReplaceSel(replacement, TRUE);

            m_documentModelCurrent->Update(range, replacement);
        }
        else
        {
            m_sidebar.LogError(_T("Surface is not matching"));
            break;
        }
    }
}


void CAcrolinxDemoSidebarCppDlg::CheckedAcrolinxsidebar1(LPDISPATCH checkResult)
{
    m_documentModelCurrent = m_documentModelRequest;
    m_sidebar.LogInfo(_T("Document is check is complete"));
    ICheckResultPtr checkResultInstance = nullptr;
    checkResult->QueryInterface(__uuidof(ICheckResult), (void**)&checkResultInstance);
    BSTR embedCheckData = _T("");
    checkResultInstance->GetEmbedCheckInformation(&embedCheckData);
    m_sidebar.LogInfo(embedCheckData);
}



void CAcrolinxDemoSidebarCppDlg::SidebarLoadedAcrolinxsidebar1(LPCTSTR url)
{
    m_sidebar.LogInfo(L"Sidebar loaded successfully");
}


BOOL CAcrolinxDemoSidebarCppDlg::PreTranslateMessage(MSG* pMsg)
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


Input_Format CAcrolinxDemoSidebarCppDlg::GetFormatFromString(CString format)
{
    Input_Format inputFormat;

    if(format == "XML")
    {
        inputFormat = IF_XML;
    }
    else if(format == "TEXT")
    {
        inputFormat = IF_TEXT;
    }
    else if(format == "HTML")
    {
        inputFormat =  IF_HTML;
    }
    else if(format == "MARKDOWN")
    {
        inputFormat = IF_MARKDOWN;
    }
    else
    {
        inputFormat = IF_AUTO;
    }

    return inputFormat;
}


void CAcrolinxDemoSidebarCppDlg::RegisterControlForAutoSizing(int iID, double horizontalMovement, double verticalMovement, double width, double height)
{
    ASSERT((horizontalMovement + width) <= 100.0);
    ASSERT((verticalMovement + height) <= 100.0);

    ControlSizing cs;

    GetDlgItem(iID, &cs.m_hWnd);
    ASSERT(cs.m_hWnd != NULL);
    cs.m_horizontalMovement = horizontalMovement / 100.0;
    cs.m_verticalMovement = verticalMovement / 100.0;
    cs.m_width = width / 100.0;
    cs.m_height = height / 100.0;
    ::GetWindowRect(cs.m_hWnd, &cs.m_initialSize);
    ScreenToClient(cs.m_initialSize);
    m_ctrlSizeList.AddTail(cs);
}


void CAcrolinxDemoSidebarCppDlg::InitializeResizer(void)
{
    if ((m_minimumSize.cx == 0) && (m_minimumSize.cy == 0))
    {
        CRect windowRect;
        GetWindowRect(windowRect);
        m_minimumSize = windowRect.Size();
    }

    CRect clientRect;
    GetClientRect(clientRect);
    m_initialSize = clientRect.Size();

}


void CAcrolinxDemoSidebarCppDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
    CDialogEx::OnGetMinMaxInfo(lpMMI);

    if (lpMMI->ptMinTrackSize.x < m_minimumSize.cx)
    {
        lpMMI->ptMinTrackSize.x = m_minimumSize.cx;
    }

    if (lpMMI->ptMinTrackSize.y < m_minimumSize.cy)
    {
        lpMMI->ptMinTrackSize.y = m_minimumSize.cy;
    }
}


void CAcrolinxDemoSidebarCppDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogEx::OnSize(nType, cx, cy);

    int xDelta = cx - m_initialSize.cx;
    int yDelta = cy - m_initialSize.cy;

    HDWP hWindowDeferPos = NULL;
    POSITION    pos;

    pos = m_ctrlSizeList.GetHeadPosition();
    while (pos)
    {
        ControlSizing element;
        element = m_ctrlSizeList.GetNext(pos);

        if (element.m_hWnd != NULL)
        {
            CRect rectCurrent(element.m_initialSize);
            rectCurrent.OffsetRect(int(xDelta * element.m_horizontalMovement), int(yDelta * element.m_verticalMovement));
            rectCurrent.right += int(xDelta * element.m_width);
            rectCurrent.bottom += int(yDelta * element.m_height);

            if (hWindowDeferPos == NULL)
            {
                hWindowDeferPos = BeginDeferWindowPos(m_ctrlSizeList.GetSize());
            }

            UINT windowPosFlags = SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER;

            if ((element.m_width != 0.0) || (element.m_height != 0.0))
            {
                windowPosFlags |= SWP_NOCOPYBITS;
            }

            DeferWindowPos(hWindowDeferPos, element.m_hWnd, NULL, rectCurrent.left, rectCurrent.top, rectCurrent.Width(), rectCurrent.Height(), windowPosFlags);
        }
    }

    if (hWindowDeferPos != NULL)
    {
        EndDeferWindowPos(hWindowDeferPos);
    }
}
