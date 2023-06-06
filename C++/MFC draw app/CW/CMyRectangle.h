#pragma once
#include "CShape.h"

class CMyRectangle :
    public CShape
{
    CPoint Points[2];

public:
    CMyRectangle(void); // Default constructor
    CMyRectangle(CPoint, CPoint); // Constructor

    void draw(CDC*); 
    bool isOnMe(CPoint);
    shapeTypes getObjectType();
};