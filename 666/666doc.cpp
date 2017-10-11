// 666Doc.cpp : implementation of the CMy666Doc class
//

#include "stdafx.h"
#include "666.h"

#include "666Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy666Doc

IMPLEMENT_DYNCREATE(CMy666Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy666Doc, CDocument)
	//{{AFX_MSG_MAP(CMy666Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy666Doc construction/destruction

CMy666Doc::CMy666Doc()
{
	// TODO: add one-time construction code here

}

CMy666Doc::~CMy666Doc()
{
}

BOOL CMy666Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy666Doc serialization

void CMy666Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy666Doc diagnostics

#ifdef _DEBUG
void CMy666Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy666Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy666Doc commands
