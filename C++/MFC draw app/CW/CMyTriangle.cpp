#include "pch.h"
#include "CMyTriangle.h"

CMyTriangle::CMyTriangle(void) {
	Points[0] = CPoint(0, 0);
	Points[1] = CPoint(0, 0);
	Points[2] = CPoint(0, 0);
	Points[3] = CPoint(0, 0);
}

CMyTriangle::CMyTriangle(CPoint p1, CPoint p2, CPoint p3) {
	Points[0] = p1;
	Points[1] = p2;
	Points[2] = p3;
	Points[3] = p1;
}

// Draw function, used to draw a triangle on scene
void CMyTriangle::draw(CDC* pDC) {
	pDC->Polyline(Points, 4); // Draws a triangle by connecting 4 points together
}

bool CMyTriangle::isOnMe(CPoint mousePoint) {

	double area_ABC = calculateArea(Points[0], Points[1], Points[2]);
	double area_PBC = calculateArea(mousePoint, Points[1], Points[2]);
	double area_APC = calculateArea(Points[0], mousePoint, Points[2]);
	double area_ABP = calculateArea(Points[0], Points[1], mousePoint);

	return (area_ABC == area_PBC + area_APC + area_ABP);
}

double CMyTriangle::calculateArea(CPoint p1, CPoint p2, CPoint p3) {
	return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

shapeTypes CMyTriangle::getObjectType() {
	return Triangle;
}