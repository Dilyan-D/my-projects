#include "pch.h"
#include "CMyPoint.h"

CMyPoint::CMyPoint(void) : CShape() {
	style = 0;
}

CMyPoint::CMyPoint(int x, int y, COLORREF outlineColor, int style) : CShape(x, y, outlineColor) {
	this->style = style;
}

void CMyPoint::draw(CDC* pDC) {

	switch (style) {
	case 0: {

		pDC->MoveTo(x - 3, y);
		pDC->LineTo(x + 3, y);
		pDC->MoveTo(x, y + 3);
		pDC->LineTo(x, y - 3);

		pDC->Rectangle(x1, y1, x2, y2);
		break;
	}
	}
}

bool CMyPoint::isOnMe(int mouseX, int mouseY) {
	return (x == mouseX) && (y == mouseY);
}