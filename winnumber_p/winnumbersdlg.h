// WinNumbersDlg.h : header file
//


#if !defined(AFX_WINNUMBERSDLG_H__7649E37F_BA8A_4D0A_8752_765F30DB5943__INCLUDED_)
#define AFX_WINNUMBERSDLG_H__7649E37F_BA8A_4D0A_8752_765F30DB5943__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CWinNumbersDlg dialog

////////////Added by Vukep
#define NO_GLOBALS
#define NO_PROTOTYPES
#include"Numlib.h"
////////////End of added by Vukep

class CWinNumbersDlg : public CDialog
{
// Construction
public:
	int restart();
	int vkp_filtrator(struct hidden *secret, struct prob *pr, struct hidden *justout);
	int nervo_addint(int val, struct hidden *temp);
	int knowns_fill(struct prob *pr);
	int vkp_debug(struct posib *p, struct prob *pr, struct hidden *secret, struct hidden *temp, struct hidden *chanceless, struct hidden *justout);
	int fourinbag(struct prob *pr, struct posib *p);
	int justgoods(struct prob *pr, struct posib p[]);
	int vkp_simplificator(struct prob *pr, struct posib p[], int flag, struct hidden *temp, struct hidden *chanceless, struct hidden *justout);
	int notanymore(struct posib *psource, struct posib *pdest);
	int fill(struct posib *p);
	int build(struct prob *pr, struct posib *p, int prflag, struct hidden *justout, int gcnt);
	int build_check(struct prob *pr, struct posib p[], struct hidden *chanceless, struct hidden *justout);
	int pos(int num);
	int priority(struct prob *pr, char *ord, int flag);
	int start(struct prob *pr);
	int situation(struct posib *p, char gr);
	int show(struct posib *p);
	int check(char *ask);
	int vkp_rand(char ord[9]);
	int deadline(char val, struct hidden *any);
	int arr_clear(char arr[], int len);
	int vkp_back();
	int h_clear(struct hidden *secret);
	int p_clear(struct posib *p);
	int pr_clear(struct prob *pr);
	

	/*Fucking globals */
	char gr; //goods + regs = 0
	char turn;
	char cnt; //=0
	char tmp; 
	char buildyn;	 //build() yes/no  =1
	char moreprty; //more priority
	char fibyn; //fourinbag() yes/no  (=1)
	char jgds; //just goods  (=0)
	char knowns;
	char autodebug;
	char simplchange;  //=0
	char tmp_cnt;
	char swich; //vkp_simplificator()
	char twoinbag, twooutbag;  //vkp_simplificator{GR4_PRTY50_50} (=0 0)
	int goods;
	int regs;
	
	struct prob pr;
	struct posib p[10];
	struct hidden secret;
	struct hidden temp;
	struct hidden chanceless;
	struct hidden justout;
	int i;
	int retbc;  //=-1
	int build_flag; //= GOAHEAD
	char miss;  //=0

	
	CWinNumbersDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWinNumbersDlg)
	enum { IDD = IDD_WINNUMBERS_DIALOG };
	int		m_goods;
	int		m_regs;
	int		m_try;
	CString	m_message;
	int		m_cnt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinNumbersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinNumbersDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlaybut();
	afx_msg void OnOkbutton();
	afx_msg void OnRegslBut();
	afx_msg void OnGoodslBut();
	afx_msg void OnGoodspBut();
	afx_msg void OnRegspBut();
	afx_msg void OnRestartBut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINNUMBERSDLG_H__7649E37F_BA8A_4D0A_8752_765F30DB5943__INCLUDED_)


