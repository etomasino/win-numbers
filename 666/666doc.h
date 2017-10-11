// 666Doc.h : interface of the CMy666Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_666DOC_H__766EF2AD_F734_499F_B40B_E0E4CAE84C5A__INCLUDED_)
#define AFX_666DOC_H__766EF2AD_F734_499F_B40B_E0E4CAE84C5A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CMy666Doc : public CDocument
{
protected: // create from serialization only
	CMy666Doc();
	DECLARE_DYNCREATE(CMy666Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy666Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy666Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy666Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_666DOC_H__766EF2AD_F734_499F_B40B_E0E4CAE84C5A__INCLUDED_)
