// ChebiDlg.h : header file
//

#if !defined(AFX_CHEBIDLG_H__D608AEFE_AF7D_455A_A542_697CB15D608D__INCLUDED_)
#define AFX_CHEBIDLG_H__D608AEFE_AF7D_455A_A542_697CB15D608D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CChebiDlg dialog

class CChebiDlg : public CDialog
{
// Construction
public:
	CChebiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChebiDlg)
	enum { IDD = IDD_CHEBI_DIALOG };
	CEdit	m_edit;
	CString	m_editv;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChebiDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChebiDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelectButton();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHEBIDLG_H__D608AEFE_AF7D_455A_A542_697CB15D608D__INCLUDED_)
