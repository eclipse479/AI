// @brief Vector2.h
// Class represents a pair of cartesian coordinates
// for use in two dimentional game systems

#pragma once

#ifndef _VECTOR_2_
#define _VECTOR_2_

class Vector2
{
	// @brief
	// Critical math data for a vector 2
public:
	union
	{
		struct
		{
			float x;
			float y;
		};
		float data[2];
	};

	Vector2();
	Vector2(const float a_x, const float a_y);

	/* @brief Subscript operator overloading to allow direct
			  data access
	   @param index of the data member
	   @return reference to indexed data member
	*/
	float& operator[] (const int a_index);

	/* @brief Casting mutable float* 
			  operator overloading
	*/
	operator float* ();
	
	/* @brief Casting read only float*
			  operator overloading
	*/
	operator const float* () const;

	//** CONSTRUCTION ZONE **//
	Vector2 operator+ (const Vector2& a_rhs) const;
	Vector2 operator- (const Vector2& a_rhs) const;
	Vector2 operator* (const float a_rhs) const;
	Vector2 operator/ (const float a_rhs) const;

	// Corresponding op=
	Vector2& operator+= (const Vector2& a_rhs);
	Vector2& operator-= (const Vector2& a_rhs);
	Vector2& operator*= (const float a_rhs);
	Vector2& operator/= (const float a_rhs);
	bool operator== (const Vector2& a_rhs) const;

	//** UTILIZATION **//
	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector2 normalised() const;

	float dot(const Vector2& a_vec2) const;
	static float dot(const Vector2& a_vec2_1, const Vector2& a_vec2_2);

	Vector2 right() const;
};

Vector2 operator* (const float a_lhs, const Vector2& a_rhs);

#endif // !_VECTOR_2_
