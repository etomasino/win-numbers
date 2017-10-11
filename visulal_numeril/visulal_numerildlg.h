// visulal_numerilDlg.h : header file
//

#if !defined(AFX_VISULAL_NUMERILDLG_H__5D75488D_8860_484A_B041_5B840360CA76__INCLUDED_)
#define AFX_VISULAL_NUMERILDLG_H__5D75488D_8860_484A_B041_5B840360CA76__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CVisulal_numerilDlg dialog

class CVisulal_numerilDlg : public CDialog
{
// Construction
public:
	CVisulal_numerilDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVisulal_numerilDlg)
	enum { IDD = IDD_VISULAL_NUMERIL_DIALOG };
	CString	m_mainedit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisulal_numerilDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVisulal_numerilDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnVukepBut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISULAL_NUMERILDLG_H__5D75488D_8860_484A_B041_5B840360CA76__INCLUDED_)
