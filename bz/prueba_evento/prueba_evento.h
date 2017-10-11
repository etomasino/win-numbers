// prueba_evento.h : main header file for the PRUEBA_EVENTO application
//

#if !defined(AFX_PRUEBA_EVENTO_H__190030FB_39FD_437C_A542_0CEFAB9D955A__INCLUDED_)
#define AFX_PRUEBA_EVENTO_H__190030FB_39FD_437C_A542_0CEFAB9D955A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrueba_eventoApp:
// See prueba_evento.cpp for the implementation of this class
//

class CPrueba_eventoApp : public CWinApp
{
public:
	CPrueba_eventoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrueba_eventoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrueba_eventoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRUEBA_EVENTO_H__190030FB_39FD_437C_A542_0CEFAB9D955A__INCLUDED_)
