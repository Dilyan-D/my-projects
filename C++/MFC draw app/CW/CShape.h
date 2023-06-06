#pragma once
#include "enumDecs.h" // Required in order to use type shapeTypes

class CShape
{
public:
	CShape(void); // Default constructor

	virtual void draw(CDC*) = 0; // Virtual draw function, used to draw a shape on scene
	virtual bool isOnMe(CPoint) = 0; // Virtual boolean function, used to check if user mouse clicks on a shape
	virtual shapeTypes getObjectType() = 0; // Virtual function, used to return an object's type (Rect/Triangle)
};