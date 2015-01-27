#pragma once
#include "Shape.h"
#include "Circle.h"
#include <iostream>

class Square : public Shape {
public:
	// Constructors Destructor
	Square(const float length, Vector2 centerPoint);
	Square();
	~Square();

	// Overlap methods
	virtual bool overlap(const Shape& shape) const;
	virtual bool overlap(const Square& square) const;
	virtual bool overlap(const Circle& circle) const;

	// Square only methods
	inline float getLength() const { return length; }
	inline float getLeftEdge() const { return centerPoint.getCoordinateX() - length / 2; }
	inline float getRightEdge() const { return centerPoint.getCoordinateX() + length / 2; }
	inline float getTopEdge() const { return centerPoint.getCoordinateY() + length / 2; }
	inline float getBottomEdge() const { return centerPoint.getCoordinateY() - length / 2; }

	// Returns readable output of Square Object
	virtual std::ostream& output(std::ostream& outStream) const;
private:
	// Private variables
	float length;
};

std::ostream& operator<<(std::ostream& outStream, const Square& square);
