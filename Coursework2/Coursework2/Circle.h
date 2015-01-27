#pragma once
#include "Shape.h"
#include "Square.h"
#include <iostream>

class Circle : public Shape{
public:
	// Constructors Destructor
	Circle(const float radius, Vector2 centerPoint);
	Circle();
	~Circle();

	// Overlap methods
	virtual bool overlap(const Shape& shape) const;
	virtual bool overlap(const Square& square) const;
	virtual bool overlap(const Circle& circle) const;

	// Circle only methods
	inline float getRadius() const { return radius; }

	// Returns readable output of Circle Object
	virtual std::ostream& output(std::ostream& outStream) const;
private:
	// Private variables
	float radius;
};

std::ostream& operator<<(std::ostream& outStream, const Circle& circle);
