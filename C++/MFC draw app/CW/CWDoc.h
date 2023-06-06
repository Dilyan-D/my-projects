
// CWDoc.h : interface of the CCWDoc class
//


#pragma once
#include "CShape.h"
#include "CMyTriangle.h"
#include "CMyRectangle.h"
#include "vector"

class CCWDoc : public CDocument
{
protected: // create from serialization only
	CCWDoc() noexcept;
	DECLARE_DYNCREATE(CCWDoc)

// Attributes
public:
	int mouseClicks; // Holds mouse click counts
	std::vector<CShape*> Shapes; // Template class vector, type CShape; holds pointers to objects of CShape class

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CCWDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
