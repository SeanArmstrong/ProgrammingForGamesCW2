#include "Vector2.h"
#include <cmath>

Vector2::Vector2(const float xVal, const float yVal){
	coord[0] = xVal;
	coord[1] = yVal;
}

Vector2::Vector2(const Vector2& v){
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
}

Vector2::~Vector2(){
}

/* Get Magnitude
 * Returns magnitude of vector as a double
 * 
 * Originally used pow(x, 2) but x*x does
 * not add to stack
*/
float Vector2::getMagnitude() const{
	return sqrt((coord[0] * coord[0]) + (coord[1] * coord[1]));
}

Vector2 Vector2::operator+(const Vector2& v){
	Vector2 newVector;
	newVector.coord[0] = (coord[0] + v.coord[0]);
	newVector.coord[1] = (coord[1] + v.coord[1]);
	return newVector;
}

Vector2 Vector2::operator-(const Vector2& v){
	Vector2 newVector;
	newVector.coord[0] = (coord[0] - v.coord[0]);
	newVector.coord[1] = (coord[1] - v.coord[1]);
	return newVector;
}

Vector2 Vector2::operator*(const float scalar){
	Vector2 newVector;
	newVector.coord[0] = (coord[0] * scalar);
	newVector.coord[1] = (coord[1] * scalar);
	return newVector;
}

/*
 If scalar is 0 will return a 
 {0,0} vector
 A exception could be thrown but this 
 is slow
*/
Vector2 Vector2::operator/(const float scalar){
	Vector2 newVector;
	if (scalar != 0){
		newVector.coord[0] = (coord[0] / scalar);
		newVector.coord[1] = (coord[1] / scalar);
	}
	return newVector;
}

float Vector2::operator*(const Vector2& v){
	return ((coord[0] * v.coord[0]) + (coord[1] * v.coord[1]));
}

Vector2& Vector2::operator+=(const Vector2& v){
	coord[0] = coord[0] + v.coord[0];
	coord[1] = coord[1] + v.coord[1];
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v){
	coord[0] = coord[0] - v.coord[0];
	coord[1] = coord[1] - v.coord[1];
	return *this;
}

Vector2& Vector2::operator/=(const float scalar){
	if (scalar != 0){
		coord[0] = coord[0] / scalar;
		coord[1] = coord[1] / scalar;
	}
	return *this;
}

bool Vector2::operator==(const Vector2& v) const {
	return ((coord[0] == v.coord[0]) && (coord[1] == v.coord[1]));
}

bool Vector2::operator!=(const Vector2& v) const {
	return (!(*this == v));
}

Vector2& Vector2::operator=(const Vector2& v) {
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	return *this;
}

Vector2 operator*(const float scalar, Vector2& v){
	return (v * scalar);
}

std::ostream& operator<< (std::ostream& outStream, Vector2 vector){
	outStream << "{" << vector.getCoordinateX() << ", " <<
		vector.getCoordinateY() << "}";
	return outStream;
}