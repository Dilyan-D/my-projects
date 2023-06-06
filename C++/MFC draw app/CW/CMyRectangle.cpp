#include "pch.h"
#include "CMyRectangle.h"

CMyRectangle::CMyRectangle(void) {
	Points[0] = CPoint(0, 0);
	Points[1] = CPoint(0, 0);
}

CMyRectangle::CMyRectangle(CPoint p1, CPoint p2){
	Points[0] = p1;
	Points[1] = p2;
}

// Draw function, used to draw a rectangle on scene
void CMyRectangle::draw(CDC* pDC) { 
	pDC->Rectangle(Points[0].x, Points[0].y, Points[1].x, Points[1].y); // Draws a rectangle by connecting two points together
}

bool CMyRectangle::isOnMe(CPoint mousePoint) {

	return // Returns true if mouse click was made on a rectangle's outlines or in 3 pixels proximity relative to the outlines

		( // In case: first point = top-left, second point = btm-right
			((mousePoint.x >= Points[0].x - 3 && mousePoint.x <= Points[0].x + 3) && (mousePoint.y >= Points[0].y && mousePoint.y <= Points[1].y))
			||
			((mousePoint.y >= Points[0].y - 3 && mousePoint.y <= Points[0].y + 3) && (mousePoint.x >= Points[0].x && mousePoint.x <= Points[1].x))
			||
			((mousePoint.x >= Points[1].x - 3 && mousePoint.x <= Points[1].x + 3) && (mousePoint.y >= Points[0].y && mousePoint.y <= Points[1].y))
			||
			((mousePoint.y >= Points[1].y - 3 && mousePoint.y <= Points[1].y + 3) && (mousePoint.x >= Points[0].x && mousePoint.x <= Points[1].x))
			)

		||

		( // In case: first point = btm-right, second point = top-left
			((mousePoint.x >= Points[0].x - 3 && mousePoint.x <= Points[0].x + 3) && (mousePoint.y <= Points[0].y && mousePoint.y >= Points[1].y))
			||
			(mousePoint.y >= Points[0].y - 3 && mousePoint.y <= Points[0].y + 3) && (mousePoint.x <= Points[0].x && mousePoint.x >= Points[1].x)
			||
			((mousePoint.x >= Points[1].x - 3 && mousePoint.x <= Points[1].x + 3) && (mousePoint.y <= Points[0].y && mousePoint.y >= Points[1].y))
			||
			(mousePoint.y >= Points[1].y - 3 && mousePoint.y <= Points[1].y + 3) && (mousePoint.x <= Points[0].x && mousePoint.x >= Points[1].x)
			);
}

shapeTypes CMyRectangle::getObjectType() {
	return Rect;
}