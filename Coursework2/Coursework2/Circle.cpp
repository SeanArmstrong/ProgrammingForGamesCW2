#include "Circle.h"
#include <cmath>
#include "CollisionDetection.h"

Circle::Circle(const float radius, Vector2 centerPoint){
	this->radius = (radius > 0 ? radius : 1);
	this->centerPoint = centerPoint;
}

Circle::Circle(){
	this->radius = 1;
	this->centerPoint = Vector2();
}

Circle::~Circle(){
}

bool Circle::overlap(const Shape& shape) const{
	return shape.overlap(*this);
}

bool Circle::overlap(const Square& square) const {
	return CollisionDetection::squareOnCircleDetection(square, *this);
}

bool Circle::overlap(const Circle& circle) const {
	return CollisionDetection::circleOnCircleDetection(*this, circle);
}

std::ostream& Circle::output(std::ostream& outStream) const {
	return outStream << "Circle: Center Point =  " << centerPoint <<
		", Radius = " << radius;
}

std::ostream& operator<<(std::ostream& outStream, const Circle& circle){
	outStream << "Circle: Center Point =  " << circle.getCenterPoint() <<
		", Radius = " << circle.getRadius();

	return outStream;
}