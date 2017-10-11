// WinNumbers.h : main header file for the WINNUMBERS application
//

#if !defined(AFX_WINNUMBERS_H__61509B6F_9A58_4F6E_AEE4_E88AA2B58A6F__INCLUDED_)
#define AFX_WINNUMBERS_H__61509B6F_9A58_4F6E_AEE4_E88AA2B58A6F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinNumbersApp:
// See WinNumbers.cpp for the implementation of this class
//

class CWinNumbersApp : public CWinApp
{
public:
	CWinNumbersApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinNumbersApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWinNumbersApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINNUMBERS_H__61509B6F_9A58_4F6E_AEE4_E88AA2B58A6F__INCLUDED_)
