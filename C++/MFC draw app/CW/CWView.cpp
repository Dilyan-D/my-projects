
// CWView.cpp : implementation of the CCWView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CW.h"
#endif

#include "CWDoc.h"
#include "CWView.h"
#include "enumDecs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


shapeTypes shapeType = Rect; // Declaration & initialization of var. shapeType to default choice - Rectangle (Rect)
CPoint firstPoint, secondPoint; // Temporary variables, required to store coordinates of points


// CCWView

IMPLEMENT_DYNCREATE(CCWView, CView)

BEGIN_MESSAGE_MAP(CCWView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCWView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CCWView::OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_TRIANGLE, &CCWView::OnShapeTriangle)
END_MESSAGE_MAP()

// CCWView construction/destruction

CCWView::CCWView() noexcept
{
	// TODO: add construction code here

}

CCWView::~CCWView()
{
}

BOOL CCWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCWView drawing


void CCWView::OnDraw(CDC* pDC)
{
	CCWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (pDoc->Shapes.size() == 0) // Required so that program draws on scene only if there's something to draw
		return;

	for (int i = 0; i < pDoc->Shapes.size(); i++) { // Executes for every element of vector Shapes
		pDoc->Shapes.at(i)->draw(pDC); // Calls function draw(CDC*) of object at Shapes[i]
	}

}


// CCWView printing


void CCWView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

// Handler for right mouse button click & release
void CCWView::OnRButtonUp(UINT nFlags, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);

	CCWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	for (int i = 0; i < pDoc->Shapes.size(); i++) { // Executes for every element of vector Shapes
		if (pDoc->Shapes.at(i)->isOnMe(point)) { // Executes if user mouse clicks on a shape
			pDoc->Shapes.erase(remove(pDoc->Shapes.begin(), pDoc->Shapes.end(), pDoc->Shapes.at(i)), pDoc->Shapes.end()); // Deletes shape that's been clicked on
			pDoc->Shapes.shrink_to_fit(); // Shrinks vector Shapes' size to the new size, theoretically freeing used memory
			Invalidate(); // Initiates redraw of scene
			pDoc->SetModifiedFlag(TRUE); // Sets status of document to modified
		}
	}
}

void CCWView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCWView diagnostics

#ifdef _DEBUG
void CCWView::AssertValid() const
{
	CView::AssertValid();
}

void CCWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCWDoc* CCWView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCWDoc)));
	return (CCWDoc*)m_pDocument;
}
#endif //_DEBUG


// CCWView message handlers


// Handler for left mouse button click & release
void CCWView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (nFlags == MK_CONTROL) { // Executes if ctrl key is pressed upon clicking the left mouse button
		OnRButtonUp(nFlags, point);
		return;
	}

	CCWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	switch (shapeType) { // Executes code based on value of shapeType
	case Rect: { // Executes if value of shapeType is Rect

		if (pDoc->mouseClicks % 2 == 0) { // Used to determine if mouse click is going to be 1st point of rectangle
			firstPoint = point;
		}
		else {
			pDoc->Shapes.push_back(new CMyRectangle(firstPoint, point)); // Pushes an object of class CMyRectangle inside vector Shapes
		}
		pDoc->mouseClicks++; // Increments value

		Invalidate(); // Initiates redraw of scene
		pDoc->SetModifiedFlag(TRUE); // Sets status of document to modified

		break;
	}
	case Triangle: { // Executes if value of shapeType is Triangle
		if (pDoc->mouseClicks == 3) {
			pDoc->mouseClicks = 0; // Resets mouse clicks once 3 have been made
		}

		switch (pDoc->mouseClicks) { // Executes code based on value of mouseClicks
		case 0: { // Executes if value of mouseClicks is 0 (1st click)
			firstPoint = point;
			break;
		}
		case 1: { // Executes if value of mouseClicks is 1 (2nd click)
			secondPoint = point;
			break;
		}
		case 2: { // Executes if value of mouseClicks is 2 (3rd click)
			pDoc->Shapes.push_back(new CMyTriangle(firstPoint, secondPoint, point)); // Pushes an object of class CMyTriangle inside vector Shapes
			break;
		}
		}
		pDoc->mouseClicks++; // Increments value

		Invalidate(); // Initiates redraw of scene
		pDoc->SetModifiedFlag(TRUE); // Sets status of document to modified
		break;
	}
	default: return; break;
	}

	CView::OnLButtonUp(nFlags, point);
}

// Handles action once user chose Rectangle from menu Shape
void CCWView::OnShapeRectangle()
{
	CCWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->mouseClicks = 0; // Resets the number of mouse clicks
	shapeType = Rect; // Lets program know shape to draw has changed to Rectangle
}

// Handles action once user chose Triangle from menu Shape
void CCWView::OnShapeTriangle()
{
	CCWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->mouseClicks = 0; // Resets the number of mouse clicks
	shapeType = Triangle; // Lets program know shape to draw has changed to Triangle
}