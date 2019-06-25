#include "Vector_3.h"
#include <cassert>
#include <cstdlib>


Vector_3::Vector_3() : x(0.0f), y(0.0f), z(0.0f)
{}

Vector_3::Vector_3(const float a_x, const float a_y, const float a_z) : x(a_x), y(a_y), z(a_z)
{}

float& Vector_3::operator[] (const int a_index)
{
	_STL_ASSERT((a_index >= 0) && (a_index < 3), "Vector 3 out of range");
	return data[a_index];
}


//changable version
Vector_3::operator float* ()
{
	return data;
}
//read only version
Vector_3::operator const float* () const
{
	return data;
}

Vector_3 Vector_3::operator + (const Vector_3& other) const
{
	return Vector_3{ x + other.x, y + other.y , z + other.z};
}

Vector_3 Vector_3::operator - (const Vector_3& other) const
{
	return Vector_3{ x - other.x, y - other.y, z - other.z };
}

Vector_3 Vector_3::operator * (float scalar) const
{
	return Vector_3{ x * scalar, y * scalar, z * scalar };
}


Vector_3 Vector_3::operator / (float scalar) const
{
	return Vector_3{ x / scalar, y / scalar, z / scalar };
}

Vector_3& Vector_3::operator += (const Vector_3& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector_3& Vector_3::operator -= (const Vector_3& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector_3& Vector_3::operator *= (const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector_3& Vector_3::operator /= (const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

float Vector_3::square_magnitude() const
{
	return (x*x) + (y*y) + (z*z);
}

float Vector_3::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector_3::normalise()
{
	*this /= magnitude();
}

Vector_3 Vector_3::normalised() const
{
	return *this / magnitude();
}

bool Vector_3::operator ==(const Vector_3& a_rhs)
{
	return (x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z);
}

Vector_3 operator*(const float a_lhs, const Vector_3& a_rhs)
{
	return a_rhs * a_lhs;
}


float  Vector_3::dot(const Vector_3& a_rhs) const
{
	return { (x * a_rhs.x) + 
			 (y * a_rhs.y) +
			 (z * a_rhs.z) };
}
float  Vector_3::dot(const Vector_3& a_lhs, const Vector_3& a_rhs)
{
	return  a_lhs.dot(a_rhs);
}


Vector_3  Vector_3::cross(const Vector_3& a_rhs) const
{
	return { (y * a_rhs.z) - (z*a_rhs.y),
		     (z * a_rhs.x) - (x*a_rhs.z),
	         (x * a_rhs.y) - (y*a_rhs.x) };
}
Vector_3 Vector_3::cross(const Vector_3& a_lhs, const Vector_3& a_rhs)
{
	return a_lhs.cross(a_rhs);
}