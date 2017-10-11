// newlineDlg.h : header file
//

#if !defined(AFX_NEWLINEDLG_H__D5116BAC_0106_49D0_8F27_37FC9C312AF2__INCLUDED_)
#define AFX_NEWLINEDLG_H__D5116BAC_0106_49D0_8F27_37FC9C312AF2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CNewlineDlg dialog

class CNewlineDlg : public CDialog
{
// Construction
public:
	CNewlineDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNewlineDlg)
	enum { IDD = IDD_NEWLINE_DIALOG };
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewlineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNewlineDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWLINEDLG_H__D5116BAC_0106_49D0_8F27_37FC9C312AF2__INCLUDED_)
