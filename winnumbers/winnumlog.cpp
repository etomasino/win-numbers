// WinNumLog.cpp : implementation file
//

#include "stdafx.h"
#include "WinNumbers.h"
#include "WinNumLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinNumLog dialog


CWinNumLog::CWinNumLog(CWnd* pParent /*=NULL*/)
	: CDialog(CWinNumLog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWinNumLog)
	m_log = _T("");
	//}}AFX_DATA_INIT
}


void CWinNumLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWinNumLog)
	DDX_Control(pDX, IDC_LOG_EDIT, m_logc);
	DDX_Text(pDX, IDC_LOG_EDIT, m_log);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWinNumLog, CDialog)
	//{{AFX_MSG_MAP(CWinNumLog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinNumLog message handlers



int CWinNumLog::log_fill(CString result)
{
//	UpdateData(TRUE);
	
	//m_logc.SetFocus();
	
	//m_logc.LineScroll(3,0 );
	
	
	//UpdateData(TRUE);
	
	m_log+=(LPCTSTR)result;
	m_log+=(LPCTSTR)'\n';
	

	if(state == ON)
		UpdateData(FALSE);
	return 0;
}

int CWinNumLog::change_state()
{
		if(state == ON)
			state=OFF;
		else if(state == OFF)
			state=ON;
		else
			return-1;
		return 0;
}

int CWinNumLog::set_state(int val)
{
	if(val == 0 || val == 1)
		state=val;
	else 
		return -1;

	return 0;

}
