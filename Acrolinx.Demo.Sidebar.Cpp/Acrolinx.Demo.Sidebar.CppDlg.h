/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Demo.Sidebar.CppDlg.h : header file
//

#pragma once
#include "acrolinxsidebar1.h"
#include "afxwin.h"

// CAcrolinxDemoSidebarCppDlg dialog
class CAcrolinxDemoSidebarCppDlg : public CDialogEx
{
    // Construction
public:
    CAcrolinxDemoSidebarCppDlg(CWnd* pParent = NULL);	// standard constructor

    // Dialog Data
    enum { IDD = IDD_ACROLINXDEMOSIDEBARCPP_DIALOG };

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
private:
    void SetInitParameters(void);
public:
    DECLARE_EVENTSINK_MAP()
    void InitFinishedAcrolinxsidebar1();
    void RequestCheckAcrolinxsidebar1(LPDISPATCH checkOptions);
    CString GetDialogText(int dialogID);
public:
    void SelectRangesAcrolinxsidebar1(LPDISPATCH matches);
    CEdit m_textbox;
    void ReplaceRangesAcrolinxsidebar1(LPDISPATCH matches);
    CComboBox m_format;
    void CheckedAcrolinxsidebar1(LPDISPATCH checkResult);
    void SidebarLoadedAcrolinxsidebar1(LPCTSTR url);
private:
    IDocumentModelPtr m_documentModelCurrent;
    IDocumentModelPtr m_documentModelRequest;
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    Input_Format GetFormatFromString(CString format);
};
