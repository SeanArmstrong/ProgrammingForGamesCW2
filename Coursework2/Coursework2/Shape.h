#pragma once
#include "Vector2.h"
#include <iostream>

class Circle;
class Square;

class Shape {
public:
	// Overlap methods
	virtual bool overlap(const Shape& shape) const = 0;
	virtual bool overlap(const Circle& circle) const = 0;
	virtual bool overlap(const Square& square) const = 0;

	// Methods used by all shapes
	inline void move(const Vector2& vector) { centerPoint = vector; }
	inline Vector2 getCenterPoint() const { return centerPoint; }
	inline float getXCoordinate() const { return centerPoint.getCoordinateX(); }
	inline float getYCoordinate() const { return centerPoint.getCoordinateY(); }

	// Returns readable output of Derived Objects
	virtual std::ostream& output(std::ostream& outStream) const = 0;
protected:
	// Variables inherited by derived classes
	Vector2 centerPoint;
	Vector2* vertices;
};

std::ostream& operator<<(std::ostream& outStream, const Shape& shape);


