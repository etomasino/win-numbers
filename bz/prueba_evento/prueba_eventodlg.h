// prueba_eventoDlg.h : header file
//

#if !defined(AFX_PRUEBA_EVENTODLG_H__C52E0DA5_3956_4241_B3D4_FE6C3138B7A9__INCLUDED_)
#define AFX_PRUEBA_EVENTODLG_H__C52E0DA5_3956_4241_B3D4_FE6C3138B7A9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CPrueba_eventoDlg dialog

///////////////////vukep

#include<winbase.h>
///////////////////////////

class CPrueba_eventoDlg : public CDialog
{
// Construction
public:
	CPrueba_eventoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrueba_eventoDlg)
	enum { IDD = IDD_PRUEBA_EVENTO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrueba_eventoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrueba_eventoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRUEBA_EVENTODLG_H__C52E0DA5_3956_4241_B3D4_FE6C3138B7A9__INCLUDED_)
