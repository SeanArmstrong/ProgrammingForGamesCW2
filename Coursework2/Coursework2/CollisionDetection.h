#pragma once
#include "Circle.h"
#include "Square.h"

class CollisionDetection
{
public:
	static bool squareOnSquareDetection(const Square& square1, const Square& square2);
	static bool circleOnCircleDetection(const Circle& circle1, const Circle& circle2);
	static bool squareOnCircleDetection(const Square& square, const Circle& circle);
};
