/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Adapter.Demo.Sidebar.Cpp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAcrolinxAdapterDemoSidebarCppApp:
// See Acrolinx.Adapter.Demo.Sidebar.Cpp.cpp for the implementation of this class
//

class CAcrolinxAdapterDemoSidebarCppApp : public CWinApp
{
public:
    CAcrolinxAdapterDemoSidebarCppApp();

// Overrides
public:
    virtual BOOL InitInstance();

// Implementation

    DECLARE_MESSAGE_MAP()
};

extern CAcrolinxAdapterDemoSidebarCppApp theApp;