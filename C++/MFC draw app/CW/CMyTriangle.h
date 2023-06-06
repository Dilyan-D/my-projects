#pragma once
#include "CShape.h"

class CMyTriangle :
    public CShape
{
    CPoint Points[4];

public:
    CMyTriangle(void); // Default constructor
    CMyTriangle(CPoint, CPoint, CPoint); // Constructor

    void draw(CDC*);
    bool isOnMe(CPoint);
    double calculateArea(CPoint, CPoint, CPoint);
    shapeTypes getObjectType();
};