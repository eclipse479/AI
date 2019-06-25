#include "Vector_4.h"
#include <cassert>
#include <cstdlib>


Vector_4::Vector_4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{}

Vector_4::Vector_4(const float a_x, const float a_y, const float a_z, const float a_w) : x(a_x), y(a_y), z(a_z), w(a_w)
{}

float& Vector_4::operator[] (const int a_index)
{
	_STL_ASSERT((a_index >= 0) && (a_index < 4), "Vector 3 out of range");
	return data[a_index];
}


//changable version
Vector_4::operator float* ()
{
	return data;
}
//read only version
Vector_4::operator const float* () const
{
	return data;
}

Vector_4 Vector_4::operator + (const Vector_4& other) const
{
	return Vector_4{ x + other.x, y + other.y , z + other.z, w  +other.w };
}

Vector_4 Vector_4::operator - (const Vector_4& other) const
{
	return Vector_4{ x - other.x, y - other.y, z - other.z,w - other.w };
}

Vector_4 Vector_4::operator * (float scalar) const
{
	return Vector_4{ x * scalar, y * scalar, z * scalar,w * scalar};
}


Vector_4 Vector_4::operator / (float scalar) const
{
	return Vector_4{ x / scalar, y / scalar, z / scalar ,w/scalar};
}

Vector_4& Vector_4::operator += (const Vector_4& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector_4& Vector_4::operator -= (const Vector_4& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector_4& Vector_4::operator *= (const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector_4& Vector_4::operator /= (const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

float Vector_4::square_magnitude() const
{
	return (x*x) + (y*y) + (z*z);
}

float Vector_4::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector_4::normalise()
{
	*this /= magnitude();
}

Vector_4 Vector_4::normalised() const
{
	return *this / magnitude();
}

bool Vector_4::operator ==(const Vector_4& a_rhs)
{
	return (x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z);
}

Vector_4 operator*(const float a_lhs, const Vector_4& a_rhs)
{
	return a_rhs * a_lhs;
}

float  Vector_4::dot(const Vector_4& a_rhs) const
{
	return { (x * a_rhs.x) +
			 (y * a_rhs.y) +
			 (z * a_rhs.z) };
}
float  Vector_4::dot(const Vector_4& a_lhs, const Vector_4& a_rhs)
{
	return  a_lhs.dot(a_rhs);
}


Vector_4  Vector_4::cross(const Vector_4& a_rhs) const
{
	return { (y * a_rhs.z) - (z*a_rhs.y),
			 (z * a_rhs.x) - (x*a_rhs.z),
			 (x * a_rhs.y) - (y*a_rhs.x),
									   w };
}
Vector_4 Vector_4::cross(const Vector_4& a_lhs, const Vector_4& a_rhs)
{
	return a_lhs.cross(a_rhs);
}