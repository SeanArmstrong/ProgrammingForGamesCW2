#include "CollisionDetection.h"

bool CollisionDetection::squareOnSquareDetection(const Square& square1, const Square& square2){
	return (square1.getLeftEdge() <= square2.getRightEdge() && 
			square1.getRightEdge() >= square2.getLeftEdge() &&
			square1.getTopEdge() >= square2.getBottomEdge() &&
			square1.getBottomEdge() <= square2.getTopEdge());
}

bool CollisionDetection::circleOnCircleDetection(const Circle& circle1, const Circle& circle2){
	// (x1 - x2)^2 + (y1 - y2)^2 < >= (r1 + r2)^2
	return (pow(circle1.getXCoordinate() - circle2.getXCoordinate(), 2) +
			pow(circle1.getYCoordinate() - circle2.getYCoordinate(), 2)) <=
			pow(circle1.getRadius() + circle2.getRadius(), 2);
}

bool CollisionDetection::squareOnCircleDetection(const Square& square, const Circle& circle){
	// Distance between center points of square and circle
	float xDistance = abs(circle.getXCoordinate() - square.getXCoordinate());
	float yDistance = abs(circle.getYCoordinate() - square.getYCoordinate());

	float halfLength = square.getLength() / 2;

	// Calculate if the center points are far enough away in the x or 
	// y axis then intersection is no possible
	if (xDistance > (halfLength + circle.getRadius()) ||
		yDistance > (halfLength + circle.getRadius())){
		return false;
	}

	// Calculate square if the distance between the two points
	// is smaller than the distance between the squares center and its
	// edge
	if ((xDistance <= (halfLength)) ||
		(yDistance <= (halfLength))){
		return true;
	}

	// Check if the Circle intercepts the corner of the square
	float cornerDistance = pow(xDistance - halfLength, 2) +
		pow(yDistance - halfLength, 2);

	return cornerDistance <= (circle.getRadius() * circle.getRadius());
}
