// visulal_numeril.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "visulal_numeril.h"
#include "visulal_numerilDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisulal_numerilApp

BEGIN_MESSAGE_MAP(CVisulal_numerilApp, CWinApp)
	//{{AFX_MSG_MAP(CVisulal_numerilApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisulal_numerilApp construction

CVisulal_numerilApp::CVisulal_numerilApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVisulal_numerilApp object

CVisulal_numerilApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVisulal_numerilApp initialization

BOOL CVisulal_numerilApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CVisulal_numerilDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
