/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Demo.Sidebar.Cpp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Acrolinx.Demo.Sidebar.Cpp.h"
#include "Acrolinx.Demo.Sidebar.CppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAcrolinxDemoSidebarCppApp

BEGIN_MESSAGE_MAP(CAcrolinxDemoSidebarCppApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAcrolinxDemoSidebarCppApp construction

CAcrolinxDemoSidebarCppApp::CAcrolinxDemoSidebarCppApp()
{
    // support Restart Manager
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}


// The one and only CAcrolinxDemoSidebarCppApp object

CAcrolinxDemoSidebarCppApp theApp;


// CAcrolinxDemoSidebarCppApp initialization

BOOL CAcrolinxDemoSidebarCppApp::InitInstance()
{
    // InitCommonControlsEx() is required on Windows XP if an application
    // manifest specifies use of ComCtl32.dll version 6 or later to enable
    // visual styles.  Otherwise, any window creation will fail.
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // Set this to include all the common control classes you want to use
    // in your application.
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();


    AfxEnableControlContainer();

    // Create the shell manager, in case the dialog contains
    // any shell tree view or shell list view controls.
    CShellManager *pShellManager = new CShellManager;

    CAcrolinxDemoSidebarCppDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();

    // Delete the shell manager created above.
    if (pShellManager != NULL)
    {
        delete pShellManager;
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}

