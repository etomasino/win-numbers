#if !defined(AFX_WINNUMLOG_H__C1BDCC95_7EDC_4FCF_8671_AF1D6A953087__INCLUDED_)
#define AFX_WINNUMLOG_H__C1BDCC95_7EDC_4FCF_8671_AF1D6A953087__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WinNumLog.h : header file
//
#include "log_globals.h"

/////////////////////////////////////////////////////////////////////////////
// CWinNumLog dialog

class CWinNumLog : public CDialog
{
// Construction
public:
	int set_state(int val);
	int change_state();
	char state;
	int log_fill(CString result);

	CWinNumLog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWinNumLog)
	enum { IDD = IDD_LOG_DIALOG };
	CEdit	m_logc;
	CString	m_log;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinNumLog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWinNumLog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINNUMLOG_H__C1BDCC95_7EDC_4FCF_8671_AF1D6A953087__INCLUDED_)
