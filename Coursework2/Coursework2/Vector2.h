#pragma once
#include <iostream>

class Vector2{
public:
	Vector2(const float x = 0.0f, const float y = 0.0f );
	Vector2::Vector2(const Vector2& v);
	~Vector2();
	inline float getCoordinateX() const { return coord[0]; }
	inline float getCoordinateY() const { return coord[1]; }

	float getMagnitude() const;

	Vector2 operator+(const Vector2& v);
	Vector2 operator-(const Vector2& v);
	Vector2 operator*(const float scalar);
	Vector2 operator/(const float scalar);
	float	operator*(const Vector2& v);
	Vector2 operator%(const Vector2& v);

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator/=(const float scalar);
	Vector2& operator%=(const Vector2& v);

	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;

	Vector2& operator=(const Vector2& v);

private:
	/* Array of Coordinates x,y
	* coord[0] = x
	* coord[1] = y
	*/
	float coord[2];
};

// Prints Vector2 in the form {x,y}
std::ostream& operator<< (std::ostream& outStream, Vector2 vector);

Vector2 operator*(const float scalar, Vector2& v);