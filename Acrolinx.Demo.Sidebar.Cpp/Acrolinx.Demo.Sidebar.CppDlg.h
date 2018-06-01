/* Copyright (c) 2018 Acrolinx GmbH */

// Acrolinx.Demo.Sidebar.CppDlg.h : header file
//

#pragma once
#include "acrolinxsidebar1.h"
#include "afxwin.h"

typedef struct
{
    HWND        m_hWnd;
    double      m_horizontalMovement;
    double      m_verticalMovement;
    double      m_width;
    double      m_height;
    CRect       m_initialSize;
}ControlSizing;

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
    void SelectRangesAcrolinxsidebar1(LPDISPATCH matches);
    void ReplaceRangesAcrolinxsidebar1(LPDISPATCH matches);
    void CheckedAcrolinxsidebar1(LPDISPATCH checkResult);
    void SidebarLoadedAcrolinxsidebar1(LPCTSTR url);
    CString GetDialogText(int dialogID);
public:
    CEdit m_textbox;
    CComboBox m_format;

private:
    IDocumentModelPtr m_documentModelCurrent;
    IDocumentModelPtr m_documentModelRequest;
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    Input_Format GetFormatFromString(CString format);

private:
    CList<ControlSizing, ControlSizing&> m_ctrlSizeList;
    CSize   m_initialSize;
    CSize   m_minimumSize;
private:
    void RegisterControlForAutoSizing(int iID, double horizontalMovement, double verticalMovement, double width, double height);
    void InitializeResizer(void);
public:
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
    afx_msg void OnSize(UINT nType, int cx, int cy);
};
