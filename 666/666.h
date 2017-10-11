// 666.h : main header file for the 666 application
//

#if !defined(AFX_666_H__FF20A6B3_388C_46DC_9015_45C295CC2549__INCLUDED_)
#define AFX_666_H__FF20A6B3_388C_46DC_9015_45C295CC2549__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy666App:
// See 666.cpp for the implementation of this class
//

class CMy666App : public CWinApp
{
public:
	CMy666App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy666App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy666App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_666_H__FF20A6B3_388C_46DC_9015_45C295CC2549__INCLUDED_)
