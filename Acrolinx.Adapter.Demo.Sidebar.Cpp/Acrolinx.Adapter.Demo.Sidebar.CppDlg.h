/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Adapter.Demo.Sidebar.CppDlg.h : header file
//

#pragma once
#include "acrolinxsidebar1.h"
#include "afxwin.h"
#include "TextBoxAdapter.h"

// The libs are copied from packages\Acrolinx.Sidebar.SDK.<version>\lib to ../acrolinx-sdk/lib in a pre build event
#if defined _M_X64
#include "..\acrolinx-sdk\lib\x64\AcrolinxInterface.h"
#else
#include "..\acrolinx-sdk\lib\x86\AcrolinxInterface.h"
#endif


// CAcrolinxAdapterDemoSidebarCppDlg dialog
class CAcrolinxAdapterDemoSidebarCppDlg : public CDialogEx
{
// Construction
public:
    CAcrolinxAdapterDemoSidebarCppDlg(CWnd* pParent = NULL);	// standard constructor

    // Dialog Data
    enum { IDD = IDD_ACROLINXADAPTERDEMOSIDEBARCPP_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    CAcrolinxsidebar1 m_sidebar;
    CEdit m_titleTextBox;
    CEdit m_descriptionTextBox;
    CEdit m_contentTextBox;
private:
    void SetInitParameters(void);
public:
    DECLARE_EVENTSINK_MAP()
    void RequestCheckAcrolinxsidebar1(LPDISPATCH checkOptions);
    void SelectRangesAcrolinxsidebar1(LPDISPATCH matches);
    void ReplaceRangesAcrolinxsidebar1(LPDISPATCH matches);
    void CheckedAcrolinxsidebar1(LPDISPATCH checkResult);
private:
    CMultiAdapter* m_multiAdapterRequest;
    CMultiAdapter* m_multiAdapterCurrent;
    CArray<CUniversalAdapter*> m_adapters;
public:
    virtual BOOL DestroyWindow();
private:
    void InitializeAdapters(void);
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};
