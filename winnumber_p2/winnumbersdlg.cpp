// WinNumbersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WinNumbers.h"
#include "WinNumbersDlg.h"



//#include "C:\Temp\dontcpp\numlib\numlib.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



#define GR3_PRTY75_0	1
#define GR3_PRTY50_25	2	

#define GR4_PRTY75_25   3
#define GR4_PRTY50_50   4

#define GOAHEAD 1
#define GOBACK 2

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinNumbersDlg dialog

CWinNumbersDlg::CWinNumbersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWinNumbersDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWinNumbersDlg)
	m_goods = 0;
	m_regs = 0;
	m_try = 0;
	m_message = _T("");
	m_cnt = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinNumbersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWinNumbersDlg)
	DDX_Control(pDX, IDC_OKBUTTON, m_okbutton);
	DDX_Text(pDX, IDC_GOODS_EDIT, m_goods);
	DDV_MinMaxInt(pDX, m_goods, 0, 4);
	DDX_Text(pDX, IDC_REGS_EDIT, m_regs);
	DDV_MinMaxInt(pDX, m_regs, 0, 4);
	DDX_Text(pDX, IDC_TRY_EDIT, m_try);
	DDX_Text(pDX, IDC_MESSAGES_EDIT, m_message);
	DDX_Text(pDX, IDC_CNT_EDIT, m_cnt);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWinNumbersDlg, CDialog)
	//{{AFX_MSG_MAP(CWinNumbersDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAYBUT, OnPlaybut)
	ON_BN_CLICKED(IDC_OKBUTTON, OnOkbutton)
	ON_BN_CLICKED(IDC_REGSL_BUT, OnRegslBut)
	ON_BN_CLICKED(IDC_GOODSL_BUT, OnGoodslBut)
	ON_BN_CLICKED(IDC_GOODSP_BUT, OnGoodspBut)
	ON_BN_CLICKED(IDC_REGSP_BUT, OnRegspBut)
	ON_BN_CLICKED(IDC_RESTART_BUT, OnRestartBut)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinNumbersDlg message handlers

BOOL CWinNumbersDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	////////////////////////////////Vukep Initializations
	//CWinNumbersDlg_globals initializacion by vukep
	gr=0;
	cnt=0;
	buildyn=1;
	fibyn=1;
	jgds=1;
	simplchange=0;
	twoinbag=twooutbag=0;
	restartyn=0;
	gr_max=4;

	retbc=-1;
	build_flag=GOAHEAD;
	miss=0;
	swich=0;

	h_clear(&justout);
	h_clear(&chanceless);
	h_clear(&temp);
	h_clear(&secret);
	pr_clear(&pr);
	start(&pr);
	autodebug = 0;
	gpyn=0;
	glyn=0;
	rpyn=0;
	rlyn=0;


	
	m_message= "Press Play button to start...";
	UpdateData(FALSE);
	
	////////////////////////////////End of Vukep's Initializations

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWinNumbersDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWinNumbersDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		////////////////////////////////////////////by vukep
	

		CPaintDC dc(this);

		HBITMAP hbitmap = ::LoadBitmap(::AfxGetInstanceHandle(), 
										MAKEINTRESOURCE(IDB_NUMPIC));
		HDC hMemDC =  ::CreateCompatibleDC(NULL);

		SelectObject(hMemDC, hbitmap);

		::StretchBlt(dc.m_hDC, 
					7,
					7,
					73,
					70,
					hMemDC,
					0,
					0,
					73,
					70,
					SRCCOPY);
		::StretchBlt(dc.m_hDC, 
					dlg_x - 80,
					7,
					73,
					70,
					hMemDC,
					0,
					0,
					73,
					70,
					SRCCOPY);

		::DeleteDC(hMemDC);
		::DeleteObject(hbitmap);
	


		/////////////////////////////////////byvkp  end

		CDialog::OnPaint();
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWinNumbersDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWinNumbersDlg::OnPlaybut() 
{
	
	build(&pr, &p[cnt], GOAHEAD, &justout, cnt);
	m_try=show(&p[cnt]);	

	m_message="Fill the Goods and Regs values and then pres 'OK'";
	m_cnt=cnt;

	

	GetDlgItem(IDC_OKBUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_GOODSP_BUT)->EnableWindow(TRUE);
	gpyn=1;

	GetDlgItem(IDC_REGSP_BUT)->EnableWindow(TRUE);
	rpyn=1;

	GetDlgItem(IDC_GOODS_EDIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_REGS_EDIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_RESTART_BUT)->EnableWindow(TRUE);
	GetDlgItem(IDC_PLAYBUT)->EnableWindow(FALSE);







	
	
	
	UpdateData(FALSE);
}

void CWinNumbersDlg::OnOkbutton() 
{
	
	char hell[100];
	int sit;
		
	UpdateData(TRUE);

	p[cnt].goods= m_goods;
	p[cnt].regs = m_regs;

	m_goods=m_regs=0;
	p[cnt].prty= (p[cnt].goods * 1. + p[cnt].regs * 1.) / 4.;
	
	//sprintf(hell, "situation= %f", p[cnt].prty);
	UpdateData(FALSE);
	
	knowns_fill(&pr);
	

	gr= p[0].goods + p[0].regs + p[1].goods + p[1].regs;

	vkp_debug(&p[cnt], &pr, &secret, &temp, &chanceless, &justout);
	vkp_filtrator(&secret, &pr, &justout);
	
	if(p[cnt].goods + p[cnt].regs == 4)
		justgoods(&pr, p);
	
	if(cnt >= 1 && fibyn==1)
	{
	  vkp_simplificator(&pr, p, situation(&p[0], gr), &temp, &chanceless, &justout);
	}

	
	cnt++;
	knowns=0;


	if(buildyn == 1)
	{
		
		build(&pr, &p[cnt], GOAHEAD, &justout, cnt);
	
		if(build_check(&pr, p, &chanceless, &justout) == -1)
		{	
		
			retbc=-1;
			autodebug=1;
			while(retbc == -1)
			{	
				///m_temp=show(&p[cnt]);
				UpdateData(FALSE);
				MessageBox("Waiting...", "Dale Chaval", MB_OK + MB_ICONEXCLAMATION);
				knowns_fill(&pr);
				p_clear(&p[cnt]);
				p[cnt].goods=3;
				build(&pr, &p[cnt], build_flag, &justout, cnt);
				vkp_debug(&p[cnt], &pr, &secret, &temp, &chanceless,
					  &justout);
				vkp_filtrator(&secret, &pr, &justout);
				retbc=build_check(&pr, p, &chanceless, &justout);
			
			 miss++;
			 if(miss > 16) //WARNING
				build_flag=GOBACK;
			 }
			autodebug=0;
		} 
	}
	build_flag=GOAHEAD; //Calming down again
	miss=0;
	m_try=show(&p[cnt]);	
	
	
	
	//sprintf(hell, "justout: %d%d%d%d chanceless: %d%d%d%d cnt=%d", justout.cifs[0].val,
	//		justout.cifs[1].val, justout.cifs[2].val, justout.cifs[3].val,
	//		chanceless.cifs[0].val, chanceless.cifs[1].val, chanceless.cifs[2].val,
	//		chanceless.cifs[3].val, vkp_back());
	//sprintf(hell, "0=%d 1=%d 2=%d 3=%d 4=%d 5%d 6=%d 7=%d 8=%d", 
	//		pr.nums[0].trys, pr.nums[1].trys, pr.nums[2].trys,
	//		pr.nums[3].trys, pr.nums[4].trys, pr.nums[5].trys,
	//		pr.nums[6].trys, pr.nums[7].trys, pr.nums[8].trys);
	//sprintf(hell, "0=%d 1=%d 2=%d 3=%d 4=%d 5%d 6=%d 7=%d 8=%d", 
	//		pr.nums[0].pos, pr.nums[1].pos, pr.nums[2].pos,
	//		pr.nums[3].pos, pr.nums[4].pos, pr.nums[5].pos,
	//		pr.nums[6].pos, pr.nums[7].pos, pr.nums[8].pos);
	//sprintf(hell, "%d%d%d%d", p[cnt].cifs[0].val, p[cnt].cifs[1].val, p[cnt].cifs[2].val,
	//		p[cnt].cifs[3].val);

	sprintf(hell, "x=%d  y=%d", dlg_x, dlg_y);

	m_message=hell;
	m_cnt=cnt;	
	
	if(restartyn == 1)
	{
		restart();
		restartyn=0;
	}
	
	gr_max=4;
	UpdateData(FALSE);
	


}


void CWinNumbersDlg::OnRegslBut() 
{
	UpdateData(TRUE);
	if(m_regs > 0)
	{
		m_regs--;
		gr_max++;
		if(m_regs == 0)
		{
			GetDlgItem(IDC_REGSL_BUT)->EnableWindow(FALSE);
		}
		if(gr_max == 1) //was 4
		{
			GetDlgItem(IDC_REGSP_BUT)->EnableWindow(TRUE);
			GetDlgItem(IDC_GOODSP_BUT)->EnableWindow(TRUE);
		}
		
	}
	else
		MessageBox("You can't choose a number\nsmaller than 0", "ERROR", MB_OK + MB_ICONSTOP);
	UpdateData(FALSE);	
}

void CWinNumbersDlg::OnGoodslBut() 
{
	UpdateData(TRUE);
	if(m_goods > 0)
	{
		m_goods--;
		gr_max++;

		if(m_goods == 0)
		{
			GetDlgItem(IDC_GOODSL_BUT)->EnableWindow(FALSE);
		}
		if(gr_max == 1) //was 4
		{
			GetDlgItem(IDC_REGSP_BUT)->EnableWindow(TRUE);
			GetDlgItem(IDC_GOODSP_BUT)->EnableWindow(TRUE);
		}
	}
	else
		MessageBox("You can't choose a number\nsmaller than 0", "ERROR", MB_OK + MB_ICONSTOP );
	UpdateData(FALSE);		
}

void CWinNumbersDlg::OnGoodspBut() 
{
	
	if(gr_max > 0)
	{
		//UpdateData(TRUE);
		m_goods++;
		gr_max--;
		//UpdateData(TRUE);

		if(gr_max == 0)
		{
			GetDlgItem(IDC_REGSP_BUT)->EnableWindow(FALSE);
			GetDlgItem(IDC_GOODSP_BUT)->EnableWindow(FALSE);
			
		}
		if(m_goods == 1) //was 0
		{
			GetDlgItem(IDC_GOODSL_BUT)->EnableWindow(TRUE);
			//GetDlgItem(IDC_GOODSL_BUT)->EnableWindow(TRUE);
		}
	
	}
	else
		MessageBox("You can't choose a number\nbigger than 4", "ERROR", MB_OK + MB_ICONSTOP);
	
	UpdateData(FALSE);

	
}

void CWinNumbersDlg::OnRegspBut() 
{
	
	if(gr_max > 0)
	{
		m_regs++;
		gr_max--;
	
		
		if(gr_max == 0)
		{
			GetDlgItem(IDC_REGSP_BUT)->EnableWindow(FALSE);
			GetDlgItem(IDC_GOODSP_BUT)->EnableWindow(FALSE);
			
		}
		if(m_regs == 1) //was 0
		{
			GetDlgItem(IDC_REGSL_BUT)->EnableWindow(TRUE);
		}
	}
	else
		MessageBox("You can't choose a number\nbigger than 4", "ERROR", MB_OK + MB_ICONSTOP);
	UpdateData(FALSE);
	
}



int CWinNumbersDlg::pr_clear(struct prob * pr)
{
		int i;
	for(i=0;i<9;i++)
	{
		pr->nums[i].val = 0;
		pr->nums[i].pos = 0;
		pr->nums[i].trys = 0;
	}
	pr->val=0;
	return 0;
}

int CWinNumbersDlg::p_clear(struct posib * p)
{

	
	int i;
	for(i=0;i<9;i++)
	{
		p->cifs[i].val=0;
		p->cifs[i].pos=0;
		p->cifs[i].trys=0;
	}
	p->goods=0;
	p->regs=0;
	return 0;
}

int CWinNumbersDlg::h_clear(struct hidden * secret)
{
	int i;
	for(i=0;i<4;i++)
	{
		secret->cifs[i].pos=0;
		secret->cifs[i].trys=0;
		secret->cifs[i].val=0;
	}
	secret->val = 0;
	return 0;
}

int CWinNumbersDlg::vkp_back()
{
	int ret=cnt;
	return(ret);

}

int CWinNumbersDlg::arr_clear(char arr [ ], int len)
{
int i;
	for(i=0;i<len;i++)
	{
		arr[i]=0;
	}
	return 0;
}

int CWinNumbersDlg::deadline(char val, struct hidden * any)
{
char y, dline=0;
	
	for(y=0;y<4;y++)
	{
		if(any->cifs[y].val == val)
			dline++;
	}
	return dline;
}


int CWinNumbersDlg::vkp_rand(char ord [ 9 ])
{
	int ran;
	char y, i;
	char element=0;
	srand(time(0));
	for(i=0;i<9;i++)
	{
		ord[i]=-1;
	}
	for(i=0; i!=124 ;i++)
	{
		ran = (rand() & 15);
		if(ran >= 9)
		{
			ran &= 7;
		}

		for(y=0;y<9;y++)
		{
			if(ran == ord[y])
				y=15;
		}
		if(y==9)
		{
			ord[element]=ran;
			element++;
		}
		if(element == 9)
		{
			i=123;
		}
	}
	return 0;

}

int CWinNumbersDlg::check(char * ask)
{
int val=0;
	int ret=0;
	
	printf("%s: ", ask);
	val=fgetc(stdin);
	ret=(val-48);
	while( fgetc(stdin) != '\n')
	{} 
	printf("Entered value:%d\n",  ret);
	while(ret> 4 || ret < 0)
	{
		printf("**Unaviable value, please enter a number betwen 1 and 4 **\n");
		printf(": ");
		val=fgetc(stdin);
		ret=(val-48);
		while( fgetc(stdin) != '\n')
		{} 
		printf("Entered value:%d\n", ret);
	}	
		

	return ret;
}


int CWinNumbersDlg::show(struct posib * p)
{
	int ret;

	ret= (p->cifs[0].val * 1000) + (p->cifs[1].val * 100) + 
		 (p->cifs[2].val * 10) + (p->cifs[3].val);

	return ret;
}


int CWinNumbersDlg::situation(struct posib * p, char gr)
{
	char ret=-1;
	if(gr==3)
	{
		if(p->prty == 0 || p->prty == 0.75)
			ret=GR3_PRTY75_0;
		else if(p->prty == 0.5 || p->prty == 0.25)
			ret=GR3_PRTY50_25;
	}
	else if(gr==4)
	{
		if(p->prty== 0.5)
			ret=GR4_PRTY50_50;
		else if(p->prty == 0.25 || p->prty == 0.75)
			ret=GR4_PRTY75_25;
	}
	
	return ret;
}


int CWinNumbersDlg::start(struct prob * pr)
{
int i;
	for(i=0; i<10; i++)
	{
		pr->nums[i].val= i+1;
		pr->nums[i].pos=15;
		pr->nums[i].trys=15;
	}
	pr->val=511;
	return 0;
}

int CWinNumbersDlg::priority(struct prob * pr, char * ord, int flag)
{
	int i, y, z=-1, b, ret=666, iplus;
	char ival, imax_min, turn=0 ;
	for(i=0; i<9; i++)
		ord[i]=99;
	
	if(flag==GOAHEAD)
	{
		ival=0;
		imax_min=9;	
		iplus=1;
	}
	else if(flag==GOBACK)
	{
		ival=8;
		imax_min=-1;
		iplus=-1;
		
	}

	
	for(i=ival; i!=imax_min; i+=iplus)
	{
		for(y=0; y<31 ; y++)
		{
			if( ((pr->nums[y].trys & 31) == 24 || (pr->nums[y].trys & 31)== 20 ||
			     (pr->nums[y].trys & 31) == 18 || (pr->nums[y].trys & 15)== 17))
			{
				for(b=0; b<9; b++)
				{
					if(ord[b] == y)
						ret=-1;
				}
				if(ret == 666)
				{
					ord[i]=y;
					y=32;
				}
			}
			
			if( ((pr->nums[y].trys + z) == 31) && (turn ==1))
			{
				for(b=0; b<9; b++)
				{
					if(ord[b] == y)
						ret=-1;
					
				}
				if(ret == 666)
				{
					ord[i]=y;
					y=32;
				}
			}
			if(y==8)
			{
				y=-1;
				z++;
				turn=1;
			}
		ret=666;
		} //for(i)
		z=0;


	}
	return 0;
}

int CWinNumbersDlg::pos(int num)
{
int ret;
	
	switch(num)
	{
	case 1:
		ret=256;
		break;
	case 2:
		ret=128;
		break;
	case 3:
		ret=64;
		break;
	case 4:
		ret=32;
		break;
	case 5:
		ret=16;
		break;
	case 6:
		ret=8;
		break;
	case 7:
		ret=4;
		break;
	case 8:
		ret=2;
		break;
	case 9:
		ret=1;
		break;
	default:
		ret=-1;
	}
	return ret;
}


int CWinNumbersDlg::build_check(struct prob * pr, struct posib p [ ], struct hidden * chanceless, struct hidden * justout)
{
	char i, y, val=0, iq, chncless=0, jstout=0;
	for(i=0; i<4; i++)
	{
		if(p[cnt].cifs[i].val == 0)
		{
			val=-1;
		}
		if(pr->nums[p[cnt].cifs[i].val -1].trys >= 16 )
		{
			knowns--;
		}
		if(chanceless->cifs[i].val != 0)
			chncless++;
		if(justout->cifs[i].val != 0)
			jstout++;
	}
	if(chncless > 0)
	{
		for(i=0;i<4;i++)
		{
			for(y=0;y<4;y++)
			{
				if(p[cnt].cifs[y].val == chanceless->cifs[i].val)
					chncless--;
			}
		}
		if(chncless != 0)
		{
			val=-1;
		}
	}
	
	if(jstout > 0)
	{
		for(i=0;i<4;i++)
		{
			for(y=0;y<4;y++)
			{
				if(p[cnt].cifs[y].val == justout->cifs[i].val && 
				   p[cnt].cifs[y].val != 0)
				{
					val=-1;
				}	
			}
		}
	}

	if(knowns != 0)
	{
		val=-1;
	}
	for(i=0; i<cnt; i++)
	{
		iq=0;
		for(y=0; y<4; y++)
		{
			if(p[cnt].cifs[y].val == p[i].cifs[y].val)
				iq++;
		}
		if(iq == 4)
			val=-1;
	}
	
	return val;
}

int CWinNumbersDlg::build(struct prob * pr, struct posib * p, int prflag, struct hidden * justout, int gcnt)
{
int cnt=15;
	int i, y=0;
	char crash=0;
	char ord[9];
	
	arr_clear(ord, sizeof(ord));
	if(prflag== GOAHEAD)
	{
		priority(pr, ord, prflag);
	}
	
	else 
	{
		vkp_rand(ord);
	}
	
	

	for(i=ord[0]; y<9; i=ord[y] )
	{
	y++;
	if( (pos(i+1) & pr->val)== pos(i+1) && pr->nums[i].val != justout->cifs[0].val &&
	pr->nums[i].val != justout->cifs[1].val && pr->nums[i].val != justout->cifs[2].val
	&& pr->nums[i].val != justout->cifs[3].val)
	{
		
		if( (((pr->nums[i].pos & 8) + (cnt & 8) + (pr->nums[i].trys & 8)) == 24) &&
			(pr->nums[i].trys != -1) ) 
		{
				
				p->cifs[0].val=pr->nums[i].val;
				p->cifs[0].pos= 8;
				cnt= (cnt ^ 8);
		}
		else if( (((pr->nums[i].pos & 4)+(cnt & 4)+(pr->nums[i].trys & 4)) == 12) &&
			(pr->nums[i].trys != -1) ) 
		{
				p->cifs[1].val=pr->nums[i].val;
				p->cifs[1].pos= 4;
				cnt= (cnt ^ 4);
		}
		else if( (((pr->nums[i].pos & 2)+(cnt & 2)+(pr->nums[i].trys & 2)) == 6) &&
			(pr->nums[i].trys != -1))
		{
				p->cifs[2].val=pr->nums[i].val;
				p->cifs[2].pos= 2;
				cnt= (cnt ^ 2);
		}
		else if( (((pr->nums[i].pos & 1)+(cnt & 1)+(pr->nums[i].trys & 1)) == 3) &&
			(pr->nums[i].trys != -1))
		{
				p->cifs[3].val=pr->nums[i].val;
				p->cifs[3].pos= 1;
				cnt= (cnt ^ 1);
		}
	}
	}//for
	
	return 0;	
}

int CWinNumbersDlg::fill(struct posib * p)
{
	p->cifs[0].pos = 8;
	p->cifs[1].pos = 4;
	p->cifs[2].pos = 2;
	p->cifs[3].pos = 1;
	
	return 0;
}


int CWinNumbersDlg::notanymore(struct posib * psource, struct posib * pdest)
{
char i;
	int ret=0;	

	for(i=0;i<4; i++)
	{
		if(psource->cifs[i].val != pdest->cifs[0].val && 
		   psource->cifs[i].val != pdest->cifs[1].val &&
		   psource->cifs[i].val != pdest->cifs[2].val &&
		   psource->cifs[i].val != pdest->cifs[3].val)
		   {	
			ret=psource->cifs[i].val;
			i=4;
		   }
	}
	return ret;
}


int CWinNumbersDlg::vkp_simplificator(struct prob * pr, struct posib p [ ], int flag, struct hidden * temp, struct hidden * chanceless, struct hidden * justout)
{
char toplay;
	char toforget;
	char i, y;
	char element=0;
			
		
	if(flag == GR3_PRTY75_0)
	{	
		if(p[0].prty > p[1].prty)
		{
			toplay=0;
			toforget=1;
			
		}	
		else
		{
			toplay=1;
			toforget=0;
		}

		if(p[cnt].prty == 0.75)
		{
			if(cnt == 2)
			{	
				pr->nums[notanymore(&p[toplay], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[toplay], &p[cnt]) -1].trys |= 16;
			}
			else
			{
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].trys |= 16;
			}
		}
		
				
	}
	
	else if(flag == GR3_PRTY50_25)
	{
		if( p[0].prty > p[1].prty)
		{
			toplay=1;
			toforget=0;
		}
		else
		{
			toplay=0;
			toforget=1;
		}

		if(simplchange == 0)
		{
			for(i=0;i<4;i++)
			{
				justout->cifs[i].val = p[toforget].cifs[i].val;
			}
			simplchange =-1; 
		}
		
			
		if(simplchange == -1 && cnt > 1)
		{
		 if(p[cnt].prty == 0.5)			
		 {
	 		 if(cnt == 2)
		 	 {
				element=notanymore(&p[toplay], &p[cnt]) -1;
				for(i=0;i<4;i++)
				{
				  if(i>=2)
				  {
					chanceless->cifs[i].val = pr->nums[element].val;
					element=notanymore(&p[toplay], (struct posib*)chanceless) -1;
					
					pr->nums[element].pos |= 16;
					pr->nums[element].trys |= 16;
					
					for(y=0;y<3;y++)
					{
						element=chanceless->cifs[y].val -1;
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
					}
					simplchange=1;

				  }
				  if(chanceless->cifs[i].val == 0)
				  {	
					chanceless->cifs[i].val = pr->nums[element].val;
					i=4;
				  }
				}
			 }
			 else
			 {
				element=notanymore(&p[cnt-1], &p[cnt]) -1;
				for(i=0;i<4;i++)
				{
				  if(i>=2)
				  {
					chanceless->cifs[i].val = pr->nums[element].val;
					element=notanymore(&p[toplay], (struct posib*)chanceless) -1;
					
					pr->nums[element].pos |= 16;
					pr->nums[element].trys |= 16;
					for(y=0;y<3;y++)
					{
						element=chanceless->cifs[y].val -1;
						
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
					}
					simplchange=1;
				  }
				  else if(chanceless->cifs[i].val == 0)
				  {
					chanceless->cifs[i].val = pr->nums[element].val;
					i=4;
				  }
				}					

			 }
			
		 }
		 if(p[cnt].prty == 0.25)
		 {
			 if(cnt ==2)
			 {
			 	pr->nums[notanymore(&p[toplay], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[toplay], &p[cnt]) -1].trys |= 16;
		       nervo_addint(pr->nums[notanymore(&p[toplay], &p[cnt]) -1].val, temp);
				for(i=0;i<4;i++)	
				{
				 if(pr->nums[p[toplay].cifs[i].val -1].val != 
				    pr->nums[notanymore(&p[toplay], &p[cnt]) -1].val)
				   {
					pr->nums[p[toplay].cifs[i].val-1].pos =-1; 
					pr->nums[p[toplay].cifs[i].val-1].trys =-1; 
				   }
				}
			 }
			 else
			 {
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].trys |= 16;
			nervo_addint(pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].val, temp);
				for(i=0;i<4;i++)
				{
					if(p[toplay].cifs[i].val != temp->cifs[0].val &&
					   p[toplay].cifs[i].val != temp->cifs[1].val &&
					   p[toplay].cifs[i].val != temp->cifs[2].val &&
					   p[toplay].cifs[i].val != temp->cifs[3].val) 
					   {
						pr->nums[p[toplay].cifs[i].val -1].pos=-1;
						pr->nums[p[toplay].cifs[i].val -1].trys=-1;
					   }

				}



			 } //else
			 simplchange=1;
			
		 } //prty 0.25
		}
			
		
		 if(simplchange == 1)
		 {
			h_clear(justout);
			h_clear(chanceless);
		
			simplchange=2;
			tmp_cnt=(cnt+1); //retarda una vuelta el trabajo del if a seguir
		 }
			
		 if(simplchange == 2 && tmp_cnt == cnt)
		 {
			if(p[cnt].prty==0.5)
			{
				h_clear(chanceless);
				h_clear(justout);
				for(i=0;i<4;i++)
				{
					for(y=0;y<4;y++)
					{
					  if(p[toforget].cifs[i].val == p[cnt].cifs[y].val)
							element++;
					}
					if(element == 0)
					{
						element=p[toforget].cifs[i].val -1;
						pr->nums[element].pos |= 16;
						pr->nums[element].trys |= 16;
						element=0;
					}
					else
					{
						element=p[toforget].cifs[i].val -1;
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
				 		element=0;
					}
				}
			}
			else if(p[cnt].prty == 0.75) //OHH SHIT
			{
				for(i=0;i<4;i++)
				{
					for(y=0;y<4;y++)
					{
					  if(p[toforget].cifs[i].val == p[cnt].cifs[y].val)
						element++;
					}
					if(element == 1)
					{
						element=p[toforget].cifs[i].val -1;
						if(swich==0)
						{
							for(y=0;y<4;y++)
							{
							 if(chanceless->cifs[y].val == 0)
							 {
								chanceless->cifs[y].val =
								pr->nums[element].val;

								y=4;
							 }
							}
							swich=1;
						}
						else if(swich ==1)
						{
							for(y=0;y<4;y++)
							{
							 if(justout->cifs[y].val == 0)
							 {
								justout->cifs[y].val =
								pr->nums[element].val;
								
								y=4;
							 }
							}
							swich=2;
						}	
						element=0;
					}

				}
			}
			tmp_cnt=(cnt+1);
		}
		
	}
	else if(flag== GR4_PRTY75_25)
	{
	
		if(p[0].prty > p[1].prty)
		{
			toplay=0;
			toforget=1;
		}
		else
		{
			toplay=1;
			toforget=0;
		}
		if(simplchange <= 1 && chanceless->cifs[0].val > 0 ) //<=======IMPORTANT!
		{	
			pr->nums[chanceless->cifs[0].val -1].pos = 15;
			pr->nums[chanceless->cifs[0].val -1].trys = 15;
			
			
		}
		if(simplchange == 0)
		{
		
			for(i=0;i<9;i++)
			{
				if(pr->nums[i].trys == 15)
				{
					chanceless->cifs[0].val=pr->nums[i].val;
					i=9;
				}
			}
			
			for(i=0;i<4;i++)
			{
				justout->cifs[i].val=p[toforget].cifs[i].val;

			}
			simplchange=1;
		}
		
		else if(simplchange == 1)
		{
			
			element=0;
			if(p[cnt].prty == 0.50)
			{
				if(cnt==2)
				{
				  element=notanymore(&p[toplay], &p[cnt]) -1;
				}
				
				else if(cnt > 2)
				{
				  element=notanymore(&p[cnt-1], &p[cnt]) -1;
				}	
				
				pr->nums[element].pos |= 16;
				pr->nums[element].trys |= 16;	
				for(i=0;i<4;i++)
				{
				  if(chanceless->cifs[i].val == 0)
				  {
				 	chanceless->cifs[i].val = pr->nums[element].val;
					i=4; 
				  }
				}	
				
				if(chanceless->cifs[3].val > 0)
				{
					element=notanymore(&p[cnt], (struct posib*)chanceless) -1;
					pr->nums[element].pos=-1;
					pr->nums[element].trys=-1;
					
					pr->nums[chanceless->cifs[0].val -1].pos = -1;	
					pr->nums[chanceless->cifs[0].val -1].trys = -1;	

					//Temorally hole
					for(i=0;i<4;i++)
					{
						element=p[toplay].cifs[i].val -1;
						if(((pr->nums[element].pos & 16) == 16) &&
						     pr->nums[element].pos != -1)
						{
							pr->nums[element].pos ^= 16;
							pr->nums[element].trys ^= 16;
						}
					}
					h_clear(chanceless);
					h_clear(justout);
					simplchange=2;
				}
				
			}
			else if(p[cnt].prty == 0.75)
			{
			//	if(cnt==2)	
				element=notanymore(&p[toplay], &p[cnt]) -1;
				
			//	else if(cnt > 2)
			//	  element=notanymore(&p[cnt-1], &p[cnt]) -1;
				
				pr->nums[element].pos = -1;
				pr->nums[element].trys = -1;
		
				pr->nums[chanceless->cifs[0].val -1].pos = -1;
				pr->nums[chanceless->cifs[0].val -1].trys = -1;

				//Temorally hole
				for(i=0;i<4;i++)
				{
					element=p[cnt].cifs[i].val -1;
					if(((pr->nums[element].pos & 16) == 16) &&
					   pr->nums[element].pos != -1)
					{
						pr->nums[element].pos ^= 16;
						pr->nums[element].trys ^= 16;
					}
				}
				
				h_clear(chanceless);
				h_clear(justout);
				simplchange=2;
			


			}	
			
			
	
		}
		if(simplchange==2)
		{
			y=0;
		
			if(swich == 0)
			{
			  for(i=0;i<4;i++)
			  {
			  	  element=p[toplay].cifs[i].val -1;
				  if(pr->nums[element].pos >= 1 && y<=1 )
				  {	
					  chanceless->cifs[y].val= pr->nums[element].val;
					  y++;
				  }
				  else if(pr->nums[element].pos >= 1 && y>1)
				  {
					  justout->cifs[y -2].val= pr->nums[element].val;
					  i=4;
				  }
			  }
			swich=1;
			}
			
			else if(swich == 1)
			{
				if(p[cnt].prty == 0.50) //No esta en el par
				{
				  for(i=0;i<4;i++)
				  {
				    element=p[cnt].cifs[i].val -1;
				    if(pr->nums[element].val != chanceless->cifs[0].val &&
				       pr->nums[element].val != chanceless->cifs[1].val &&
				       pr->nums[element].val != chanceless->cifs[2].val &&
				       pr->nums[element].val != chanceless->cifs[3].val )
				    {
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
				    }
				  }
				}
				else if(p[cnt].prty == 0.75) // esta en el par
				{
				  for(i=0;i<4;i++)
				  {		
				    element=p[toforget].cifs[i].val -1;
				    if(pr->nums[element].val != p[cnt].cifs[0].val &&
				       pr->nums[element].val != p[cnt].cifs[1].val &&
				       pr->nums[element].val != p[cnt].cifs[2].val &&
				       pr->nums[element].val != p[cnt].cifs[3].val )
				     {
					pr->nums[element].pos = -1;
					pr->nums[element].trys = -1;
				     }
				   }
				}
			


	  
			 	element=justout->cifs[0].val -1;
			 	for(i=0;i<4;i++)
			 	{
					if(chanceless->cifs[i].val == 0)
					{
				 	    chanceless->cifs[i].val = pr->nums[element].val;
					    h_clear(justout);
					    i=4;
					}
			 	}		
				simplchange=3;		
					
			}//swich==1
		}
			
		else if(simplchange == 3)
		{
			if(fibyn == 1)
			{
				for(i=0;i<4;i++)
				{
				    element=p[toforget].cifs[i].val -1;
				    if(pr->nums[element].val == p[cnt].cifs[0].val ||
				       pr->nums[element].val == p[cnt].cifs[1].val ||
				       pr->nums[element].val == p[cnt].cifs[2].val ||
				       pr->nums[element].val == p[cnt].cifs[3].val)
				    {
					pr->nums[element].pos=-1;
					pr->nums[element].trys=-1;
				    }
				}
				h_clear(chanceless);
			
				for(i=0;i<9;i++)
				{
					if(pr->nums[i].pos > -1)
					{
						pr->nums[i].pos |= 16;	
						pr->nums[i].trys |= 16;	
						for(y=0;y<4;y++)
						{
						   if(chanceless->cifs[y].val == 0)
						   {
							chanceless->cifs[y].val =
							pr->nums[i].val;
							y=4;
						   }
						}
					}
				}
			}//if(fibyn == 1)
		}//if(simplchange==3)
	}//GR4_PRTY75_25	
	
	else if(flag == GR4_PRTY50_50)
	{
		toplay=0;
		toforget=1;
		
		if(simplchange == 0)
		{
			for(i=0;i<4;i++)
			{
				justout->cifs[i].val = p[toforget].cifs[i].val;
				
			}
			for(i=0;i<9;i++)
			{
				if(pr->nums[i].trys == 15)
				{
					chanceless->cifs[0].val = pr->nums[i].val;
					i=9;
				}
			}

			simplchange=1;
		}
		
		else if(simplchange == 1)	
		{
			if(p[cnt].prty == 0.5)
			{
				element=notanymore(&p[toplay], &p[cnt]) -1;
				for(i=0;i<4;i++)
				{
				  if(chanceless->cifs[i].val == 0)
				  {
				    chanceless->cifs[i].val = pr->nums[element].val;
				    i=4; 
				  }
				}
				twooutbag++;
			}
			else if(p[cnt].prty == 0.25)
			{
				element=notanymore(&p[toplay], &p[cnt]) -1;
				pr->nums[element].pos |= 16;
				pr->nums[element].trys |= 16;
				for(i=0;i<4;i++)
				{
				  if(chanceless->cifs[i].val == 0)
				  {
				    chanceless->cifs[i].val = pr->nums[element].val;
				    i=4;
				  }
				}
				twoinbag++;
			}	
			
			if(twooutbag == 2)
			{
				for(i=0;i<4;i++)
				{
					element=chanceless->cifs[i].val -1;
					if(pr->nums[element].pos < 16)
					{
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
						
					}	
				}
				for(i=0;i<4;i++)
				{
					element=p[toplay].cifs[i].val -1;
					if(pr->nums[element].pos != -1 && 
					   pr->nums[element].pos < 16)
					{
						pr->nums[element].pos |= 16;
						pr->nums[element].trys |= 16;
					}
				}
			}
			if(twoinbag==2)
			{
				for(i=0;i<4;i++)
				{
					element=p[toplay].cifs[i].val -1;
					if(pr->nums[element].pos < 16)
					{
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
					}
				}
			}

			if(twoinbag == 2 || twooutbag == 2)
			{
				twoinbag=0;
				twooutbag=0;
				h_clear(chanceless);
				h_clear(justout);
				simplchange=2;
			}
		}

		else if(simplchange == 2)
		{
			if(p[cnt].prty == 0.5)
			{
				for(i=0;i<4;i++)
				{
					element=p[cnt].cifs[i].val -1;
					if(pr->nums[element].pos < 16)
					{
						pr->nums[element].pos = -1;
						pr->nums[element].trys = -1;
					}		

				}
				h_clear(chanceless);
				h_clear(justout);
			}
			else if(p[cnt].prty == 0.75)
			{
				y=0;
				for(i=0;i<4;i++)
				{
					element=p[cnt].cifs[i].val -1;
					if(pr->nums[element].pos < 16 && 
					   pr->nums[element].val != justout->cifs[0].val)
					{
						y++;
					}				

					if(y == 1)
					{
					 justout->cifs[0].val = pr->nums[element].val;
					 if(chanceless->cifs[0].val == 0)	
						 y=10;
					}
				
					else if(y == 11)
					{
					 chanceless->cifs[0].val = pr->nums[element].val;
					 i=4;
					}
				}
			}		
		}
	}	


	for(i=0;i<9;i++)
	{	
		if(pr->nums[i].pos >= 16)
			nervo_addint(pr->nums[i].val, temp);
	}
	return 0;
}

int CWinNumbersDlg::justgoods(struct prob * pr, struct posib p [])
{
int i, y;
	for(i=cnt; i>-1; i--)
	{
		if(p[i].jgoods==1)
		{
			for(y=0; y<4; y++)
			{
			   if(p[cnt].cifs[0].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[0].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[0].val -1].trys = (p[i].cifs[y].pos | 16);
			   }
		
			   if(p[cnt].cifs[1].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[1].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[1].val -1].trys = (p[i].cifs[y].pos | 16);
			   }
				
			   if(p[cnt].cifs[2].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[2].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[2].val -1].trys = (p[i].cifs[y].pos | 16);
			   }

		  	   if(p[cnt].cifs[3].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[3].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[3].val -1].trys = (p[i].cifs[y].pos | 16);
			   }
			}
		}
	}
	return 0;
}


int CWinNumbersDlg::fourinbag(struct prob * pr, struct posib * p)
{
int i;
	
	if(fibyn == 1)
	{
	pr->val=0; //Vaciado temporal
	
	for(i=0; i<9; i++)
	{
		if(i < 4)
		{
		pr->val= pr->val | pos(p->cifs[i].val);
		pr->nums[p->cifs[i].val -1].pos = (pr->nums[p->cifs[i].val -1].pos | 16);
		pr->nums[p->cifs[i].val -1].trys = (pr->nums[p->cifs[i].val -1].trys | 16);
		}
	

		if(pr->nums[i].val != p->cifs[0].val)
			if(pr->nums[i].val != p->cifs[1].val)
				if(pr->nums[i].val != p->cifs[2].val)
					if(pr->nums[i].val != p->cifs[3].val)
					{
						pr->nums[i].trys=-1;
						pr->nums[i].pos=-1;
					}
	}
	}
	

	fibyn=0;
	return 0;
}




int CWinNumbersDlg::vkp_debug(struct posib * p, struct prob * pr, struct hidden * secret, struct hidden * temp, struct hidden * chanceless, struct hidden * justout)
{
int i, y, element, ming=0, minr=0;

///////////////////////// No body is gonna safe /////////////////////	
	for(i=0; i<9; i++)
	{
		if(pr->nums[i].pos==0)
		{	
			pr->nums[i].pos=-1;
			pr->nums[i].trys=-1;	
			pr->val= (pr->val ^ pos(pr->nums[i].val));
		}
		else if(pr->nums[i].pos == -1)
		{
			pr->val= (pr->val ^ pos(pr->nums[i].val));
		}	
	}
	
	for(i=0; i<4; i++)
	{
		element=p->cifs[i].val -1;
		if(pr->nums[element].trys != 0)
		{
			switch(i)
			{
				case 0:
					pr->nums[element].trys= (pr->nums[element].trys ^ 8);
					break;
				case 1:
					pr->nums[element].trys= (pr->nums[element].trys ^ 4);
					break;
				case 2:
					pr->nums[element].trys= (pr->nums[element].trys ^ 2);
					break;
				case 3:
					pr->nums[element].trys= (pr->nums[element].trys ^ 1);
					break;
			}
		}
		if(pr->nums[element].trys == 0 || pr->nums[element].trys == 16) 
			pr->nums[element].trys = pr->nums[element].pos;

	}	
				
	if(cnt == 1)
	{
		if(gr == 3)
		{
			for(i==0; i<9; i++)
			{	
				if(pr->nums[i].trys == 15)
				{
					nervo_addint(pr->nums[i].val, temp);
					pr->nums[i].trys |= 16;
					pr->nums[i].pos |= 16;
					i=10;
				}
			}		
		}	
	}	

////////////////////////// Just for some stupids /////////////////////

	if(p->goods == 4)
	{	
		MessageBox("I WIN!", "You Loose", MB_ICONINFORMATION + MB_OK);
		start(pr);
		restartyn=1;;

	}
	else if( (p->goods + p->regs) == 4)
	{
		fourinbag(pr, p);
		h_clear(chanceless);
		h_clear(justout);
	}
	if(p->goods>0 && p->goods<4 && p->regs==0 && autodebug==0)
	{	
		p->jgoods=1;
		jgds++;
	}
	if( p->goods == 0)
	{
		if(p->regs == 0)
		{
			for(i=0; i<4; i++)
			{
				element=(p->cifs[i].val) -1;
				for(y=0; y< 4; y++)
				{
					if(pr->nums[element].val == secret->cifs[y].val)
						y=11;
				}
				if(y<5)
				{
					pr->nums[element].pos=0;
					pr->nums[element].trys=-1;
					pr->val=(pr->val) ^ pos(element+1);
				}
			}
		}

		else
		{
		
			for(i=0; i<4; i++)
			{	
				element=(p->cifs[i].val) -1;
				pr->nums[element].pos= p->cifs[i].pos ^ pr->nums[element].pos;	
				pr->nums[element].trys &= pr->nums[element].pos;
				switch(pr->nums[element].pos)
				{
				case 17:
					pr->nums[element].trys = pr->nums[element].pos;
					secret->cifs[3].val=pr->nums[element].val;
					secret->val= secret->val | 1;
					ming++;
					minr--;
					break;
				case 18:
					pr->nums[element].trys = pr->nums[element].pos;
					secret->cifs[2].val=pr->nums[element].val;
					secret->val= secret->val | 2;
					ming++;
					minr--;
					break;
				case 20:
					pr->nums[element].trys = pr->nums[element].pos;
					secret->cifs[1].val=pr->nums[element].val;
					secret->val= secret->val | 4;
					ming++;
					minr--;
					break;
				case 24:
					pr->nums[element].trys = pr->nums[element].pos;
					secret->cifs[0].val=pr->nums[element].val;
					secret->val= secret->val | 8;
					ming++;
					minr--;
					break;
				}
			}
		}
	}
	return 0;
}

int CWinNumbersDlg::knowns_fill(struct prob * pr)
{
char i, ret=0;

	for(i=0;i<9;i++)
	{
		if(pr->nums[i].trys >= 16 && pr->nums[i].trys <=31)
			ret++;
	}
	knowns =ret;
	return 0;
}

int CWinNumbersDlg::nervo_addint(int val, struct hidden * temp)
{
int i;
	char turn=0;

	for(i=0;i<4;i++)
	{
		if(temp->cifs[i].val == val)
			turn=1;
	}
	if(turn ==0)
	{
		for(i=0;i<4;i++)
		{
			if(temp->cifs[i].val == 0)
			{
				temp->cifs[i].val=val;
				i=5;
			}
		}
	}
	return 0;
}

int CWinNumbersDlg::vkp_filtrator(struct hidden * secret, struct prob * pr, struct hidden * justout)
{
int i, y; 
	char a, b ,c ,d, v8, v4, v2, v1;
	char knowns=0;
	a=b=c=d=v8=v4=v2=v1=0;
	
	for(i=0; i<9; i++)
	{
		for(y=0; y < 4; y++)
		{
			if(pr->nums[i].val == secret->cifs[y].val)
				y=5;
		}
		if(y < 5 )
		{
		
			if(((pr->nums[i].pos & secret->val) == secret->val) &&
			    (pr->nums[i].pos != -1))
			{
				pr->nums[i].pos= pr->nums[i].pos ^ secret->val;
				pr->nums[i].trys= pr->nums[i].trys & pr->nums[i].pos;
			
				if(pr->nums[i].trys == 0)
					pr->nums[i].trys= pr->nums[i].pos;
			}
		}
	
	//leer vkp_filtrator.txt
	if(pr->nums[i].trys == 17 || pr->nums[i].trys == 18 || pr->nums[i].trys == 20 || 
	   pr->nums[i].trys == 24) //Evitamos que se repita una cifra con valor trys minimo
	{
		switch(pr->nums[i].trys)
		{
			case 17:
				if(a != 0)
				{
					if(a>0)
						pr->nums[a-1].trys = pr->nums[a-1].pos;
					else
						pr->nums[i].trys = pr->nums[i].pos;
				
				}
				
				else if(pr->nums[i].pos != 17 )
					a=(pr->nums[i].val);
				else
					a=-1;
				break;
			case 18:
				if(b != 0)
				{
					if(b>0)
						pr->nums[b-1].trys = pr->nums[b-1].pos;
					else
						pr->nums[i].trys=pr->nums[i].pos;
				}
				
				else if(pr->nums[i].pos != 18)
					b=(pr->nums[i].val);
				else;
					b=-1;
				break;
			case 20:
				if(c != 0)
				{
					if(c>0)
						pr->nums[c-1].trys = pr->nums[c-1].pos;
					else
						pr->nums[i].trys = pr->nums[i].pos;
				}
				else if(pr->nums[i].pos != 20)
					c=(pr->nums[i].val);
				else
					c=-1;
				break;
			case 24:
				if(d != 0)
				{
					if(d>0)
						pr->nums[d-1].trys = pr->nums[d-1].pos;
					else
						pr->nums[i].trys=pr->nums[i].pos;
				}
				else if(pr->nums[i].pos != 24)
					d=(pr->nums[i].val);
				else
					d=-1;
				break;
		}

	}
	//ver vkp_filtrator.txt ->apendice 2
	
	if(((pr->nums[i].trys & 8) == 8) && (pr->nums[i].trys != -1) && 
	     deadline(pr->nums[i].val, justout) == 0)
		v8++;
	if(((pr->nums[i].trys & 4) == 4) && (pr->nums[i].trys != -1) &&
	     deadline(pr->nums[i].val, justout) == 0)
		v4++;
	if(((pr->nums[i].trys & 2) == 2) && (pr->nums[i].trys != -1) &&
	     deadline(pr->nums[i].val, justout) == 0)
		v2++;
	if(((pr->nums[i].trys & 1) == 1) && (pr->nums[i].trys != -1) &&
	     deadline(pr->nums[i].val, justout) == 0)
		v1++;


	/////////////////Another thing/////////////
	if(pr->nums[i].trys >= 16 || pr->nums[i].trys <=31)
		knowns++;

	///////////////////////////////////////////
	
	} //for


	if(v8==0 || v4==0 || v2==0 || v1==0)
	{
	
		if(v8==0)
		{
			for(y=0;y<9;y++)
			{
				if(((pr->nums[y].pos & 8) == 8) && (pr->nums[y].pos != -1))
					pr->nums[y].trys = (pr->nums[y].trys | 8);
			}
		}		
		if(v4==0)
		{
			for(y=0; y<9; y++)
			{
				if(((pr->nums[y].pos & 4) == 4) && (pr->nums[y].pos != -1))
					pr->nums[y].trys = (pr->nums[y].trys | 4);
			}
		}
		if(v2==0)
		{
			for(y=0; i<9; y++)
			{
				if(((pr->nums[y].pos & 2) == 2) && (pr->nums[y].pos != -1))
					pr->nums[y].trys = (pr->nums[y].trys | 2);
			}
		}
		if(v1==0)
		{
			for(y=0; y<9; y++)
			{
				if(((pr->nums[y].pos & 1) == 1) && (pr->nums[y].pos != -1))
					pr->nums[y].trys = (pr->nums[y].trys | 1);
			}
		} 
		
	}	
		
	
	a=b=c=d=v8=v4=v2=v1=0;

	
	return 0;
	

}

int CWinNumbersDlg::restart()
{
	gr=0;
	cnt=0;
	buildyn=1;
	fibyn=1;
	jgds=1;
	simplchange=0;
	twoinbag=twooutbag=0;

	retbc=-1;
	build_flag=GOAHEAD;
	miss=0;
	swich=0;

	h_clear(&justout);
	h_clear(&chanceless);
	h_clear(&temp);
	h_clear(&secret);
	pr_clear(&pr);
	start(&pr);
	autodebug = 0;
	m_goods=0;
	m_regs=0;
	m_try=0;
	
	build(&pr, &p[cnt], GOAHEAD, &justout, cnt);
	m_try=show(&p[cnt]);	

	m_message="Fill the Goods and Regs values and then pres 'OK'";
	m_cnt=cnt;

	
	UpdateData(FALSE);
	return 0;
}

void CWinNumbersDlg::OnRestartBut() 
{
	restart();	

}

void CWinNumbersDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	dlg_y=cy;
	dlg_x=cx;
//	Invalidate();
	
}


