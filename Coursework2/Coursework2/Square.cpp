#include "Square.h"
#include "CollisionDetection.h"

Square::Square(const float length, Vector2 centerPoint){
	this->length = (length > 0 ? length : 2);
	this->centerPoint = centerPoint;
}

Square::Square(){
	this->length = 2;
	this->centerPoint = Vector2();
}

Square::~Square(){
}

bool Square::overlap(const Shape& shape) const {
	return shape.overlap(*this);
}

bool Square::overlap(const Square& square) const {
	return CollisionDetection::squareOnSquareDetection(*this, square);
}

bool Square::overlap(const Circle& circle) const {
	return CollisionDetection::squareOnCircleDetection(*this, circle);
}

std::ostream& Square::output(std::ostream& outStream) const {
	return outStream << "Square: Center Point = " << centerPoint <<
		", Length = " << length;
}

std::ostream& operator<<(std::ostream& outStream, const Square& square){
	outStream << "Square: Center Point = " << square.getCenterPoint() <<
		", Length = " << square.getLength();

	return outStream;
}