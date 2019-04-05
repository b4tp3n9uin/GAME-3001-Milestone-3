#include "Vector2.h"


//CONSTRUCTORS
Vector2::Vector2() : x(0), y(0) { }
Vector2::Vector2(float xValue, float yValue) : x(xValue), y(yValue) { }
Vector2::Vector2(const Vector2 & v) : x(v.x), y(v.y) { }
Vector2::Vector2(const Vector2 * v) : x(v->x), y(v->y) { }

//DECONSTRUCTOR
Vector2::~Vector2() { }

//METHODS
void Vector2::Set(float xValue, float yValue) { x = xValue; y = yValue; }

float Vector2::Length() const { return sqrt(x * x + y * y); }
float Vector2::LengthSquared() const { return x * x + y * y; }
float Vector2::Distance(const Vector2 & v) const { return sqrt(((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y))); }
float Vector2::DistanceSquared(const Vector2 & v) const { return ((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y)); }
float Vector2::Dot(const Vector2 & v) const { return x * v.x + y * v.y; }

Vector2 Vector2::OrthoNormal() const { return Vector2(-y, x); }
Vector2 Vector2::Normalized() const
{
	float normalX = 0;
	float normalY = 0;
	if (Length() != 0)
	{
		normalX = x / Length();
		normalY = y / Length();
	}
	return Vector2(normalX, normalY);
}
Vector2 & Vector2::Normalize()
{
	if (Length() != 0)
	{
		float length = Length();
		x /= length; y /= length;
		return *this;
	}

	x = y = 0;
	return *this;
}

const Vector2 Vector2::Rotation(const float& angle) const
{
	return Vector2(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}

void Vector2::Rotate(const float& angle)
{
	*this = Rotation(angle);
}


