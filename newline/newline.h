// newline.h : main header file for the NEWLINE application
//

#if !defined(AFX_NEWLINE_H__59A88F8C_4F83_4BF0_B7E4_3BF90683A9F3__INCLUDED_)
#define AFX_NEWLINE_H__59A88F8C_4F83_4BF0_B7E4_3BF90683A9F3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNewlineApp:
// See newline.cpp for the implementation of this class
//

class CNewlineApp : public CWinApp
{
public:
	CNewlineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewlineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNewlineApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWLINE_H__59A88F8C_4F83_4BF0_B7E4_3BF90683A9F3__INCLUDED_)
