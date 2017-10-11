// 666View.cpp : implementation of the CMy666View class
//

#include "stdafx.h"
#include "666.h"

#include "666Doc.h"
#include "666View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy666View

IMPLEMENT_DYNCREATE(CMy666View, CView)

BEGIN_MESSAGE_MAP(CMy666View, CView)
	//{{AFX_MSG_MAP(CMy666View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy666View construction/destruction

CMy666View::CMy666View()
{
	// TODO: add construction code here

}

CMy666View::~CMy666View()
{
}

BOOL CMy666View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy666View drawing

void CMy666View::OnDraw(CDC* pDC)
{
	CMy666Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy666View printing

BOOL CMy666View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy666View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy666View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy666View diagnostics

#ifdef _DEBUG
void CMy666View::AssertValid() const
{
	CView::AssertValid();
}

void CMy666View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy666Doc* CMy666View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy666Doc)));
	return (CMy666Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy666View message handlers
