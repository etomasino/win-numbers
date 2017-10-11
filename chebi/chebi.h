// Chebi.h : main header file for the CHEBI application
//

#if !defined(AFX_CHEBI_H__27FAACC7_93C4_4EDE_8277_F6D98D88A7C7__INCLUDED_)
#define AFX_CHEBI_H__27FAACC7_93C4_4EDE_8277_F6D98D88A7C7__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChebiApp:
// See Chebi.cpp for the implementation of this class
//

class CChebiApp : public CWinApp
{
public:
	CChebiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChebiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChebiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHEBI_H__27FAACC7_93C4_4EDE_8277_F6D98D88A7C7__INCLUDED_)