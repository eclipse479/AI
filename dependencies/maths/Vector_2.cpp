#include "Vector_2.h"
#include <cassert>
#include <cstdlib>


Vector_2::Vector_2(const float a_x /* = 0.0f*/, const float a_y/* = 0.0f*/)
	:  data { a_x, a_y }
{}

float& Vector_2::operator[] (const int a_index)
{
	_STL_ASSERT((a_index >= 0) && (a_index <2),"Vector 2 out of range");
	return data[a_index];
}


//changable version
Vector_2::operator float* ()
{
	return data;
}
//read only version
Vector_2::operator const float* () const
{
	return data;
}

Vector_2 Vector_2::operator + (const Vector_2& other) const
{
	return Vector_2{ x + other.x, y + other.y};
}

Vector_2 Vector_2::operator - (const Vector_2& other) const
{
	return Vector_2{ x - other.x, y - other.y };
}


Vector_2 Vector_2::operator * (float scalar) const
{ 
	return Vector_2{ x * scalar, y * scalar};
}


Vector_2 Vector_2::operator / (float scalar) const
{
	return Vector_2{ x / scalar, y / scalar };
}


Vector_2& Vector_2::operator += (const Vector_2& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector_2& Vector_2::operator -= (const Vector_2& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector_2& Vector_2::operator *= (const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector_2& Vector_2::operator /= (const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

float Vector_2::square_magnitude() const
{
	return (x*x) + (y*y);
}

float Vector_2::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector_2::normalise()
{
	*this /= magnitude();
}

Vector_2 Vector_2::normalised() const
{
	return *this / magnitude();
}

bool Vector_2::operator ==(const Vector_2& a_rhs)
{
	return (x == a_rhs.x) && (y == a_rhs.y);
}

Vector_2 operator*(const float a_lhs, const Vector_2& a_rhs)
{
	return a_rhs * a_lhs;
}

float  Vector_2::dot(const Vector_2& a_rhs) const
{
	return { (x * a_rhs.x) + (y * a_rhs.y) };
}

float Vector_2::dot(const Vector_2& a_lhs, const Vector_2& a_rhs)
{
	return { a_lhs.dot(a_rhs) };
}

Vector_2 Vector_2::right() const
{
	return { y, -x };
}