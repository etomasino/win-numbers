// 666View.h : interface of the CMy666View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_666VIEW_H__54E8AFCB_B772_4FB8_A067_AAA1D2D702F8__INCLUDED_)
#define AFX_666VIEW_H__54E8AFCB_B772_4FB8_A067_AAA1D2D702F8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMy666View : public CView
{
protected: // create from serialization only
	CMy666View();
	DECLARE_DYNCREATE(CMy666View)

// Attributes
public:
	CMy666Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy666View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy666View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy666View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 666View.cpp
inline CMy666Doc* CMy666View::GetDocument()
   { return (CMy666Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_666VIEW_H__54E8AFCB_B772_4FB8_A067_AAA1D2D702F8__INCLUDED_)
