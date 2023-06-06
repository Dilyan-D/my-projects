
// CWDoc.cpp : implementation of the CCWDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CW.h"
#endif

#include "CWDoc.h"
#include <propkey.h>

#include "enumDecs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCWDoc

IMPLEMENT_DYNCREATE(CCWDoc, CDocument)

BEGIN_MESSAGE_MAP(CCWDoc, CDocument)
END_MESSAGE_MAP()


// CCWDoc construction/destruction

CCWDoc::CCWDoc() noexcept
{
	// TODO: add one-time construction code here

}

CCWDoc::~CCWDoc()
{
}

BOOL CCWDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	Shapes.clear(); Shapes.shrink_to_fit(); // Shrinks vector Shapes' size to 0, theoretically freeing used memory
	mouseClicks = 0; // Resets the number of mouse clicks


	return TRUE;
}


// CCWDoc serialization

void CCWDoc::Serialize(CArchive& ar)
{
	CShape* pointer; // Pointer to base class
	shapeTypes objType;

	int vectorSize = Shapes.size(),
		objSize;

	if (ar.IsStoring()) // Saving file
	{
		ar.Write(&vectorSize, sizeof(vectorSize)); // First, write Shapes' size

		for (int i = 0; i < vectorSize; i++) { // Executes for every element of Shapes
			objType = Shapes[i]->getObjectType(); // Gets i element of Shapes & sets value inside objType

			switch (objType) { // Executes code based on value of objType
			case Rect: { // Executes if value of objType is Rect
				objSize = sizeof(CMyRectangle); // Sets size of class CMyRectangle in bytes inside variable objSize
				break;
			}
			case Triangle: { // Executes if value of objType is Triangle
				objSize = sizeof(CMyTriangle); // Sets size of class CMyTriangle in bytes inside variable objSize
				break;
			}
			default: return; break; // If no case was entered, return; it shouldn't be possible to reach this point
			}

			ar.Write(&objType, sizeof(objType)); // Write object's type...
			ar.Write(Shapes[i], objSize); // ..and also the current object

		}
		SetModifiedFlag(FALSE); // And last but not least, set status of document to unmodified once saved
	}
	else // Opening file
	{
		Shapes.clear(); Shapes.shrink_to_fit(); // Shrinks vector Shapes' size to 0, theoretically freeing used memory

		ar.Read(&vectorSize, sizeof(vectorSize)); // First, read Shapes' size

		for (int i = 0; i < vectorSize; i++) { // Executes for every element of Shapes
			ar.Read(&objType, sizeof(objType)); // Reads object's type

			switch (objType) { // Executes code based on value of objType

			case Rect: { // Executes if value of objType is Rect

				pointer = new CMyRectangle; // Points pointer towards an object of class CMyRectangle
				ar.Read(pointer, sizeof(CMyRectangle)); // Reads pointer
				Shapes.push_back(pointer); // Pushes the object that the pointer's pointing to inside vector Shapes
				break;

			}
			case Triangle: { // Executes if value of objType is Triangle

				pointer = new CMyTriangle; // Points pointer towards an object of class CMyTriangle
				ar.Read(pointer, sizeof(CMyTriangle)); // Reads pointer
				Shapes.push_back(pointer); // Pushes the object that the pointer's pointing to inside vector Shapes
				break;

			}
			default: return; break;
			}
		}
		SetModifiedFlag(FALSE); // And last but not least, set status of document to unmodified once saved
	}
}
#ifdef SHARED_HANDLERS

// Support for thumbnails
void CCWDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CCWDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CCWDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCWDoc diagnostics

#ifdef _DEBUG
void CCWDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCWDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCWDoc commands
