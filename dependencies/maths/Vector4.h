// @brief Vector4.h
// Class represents a pair of cartesian coordinates
// for use in two dimentional game systems

#pragma once

#ifndef _VECTOR_4_
#define _VECTOR_4_

class Vector4
{
	// @brief
	// Critical math data for a vector 4
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];
	};

	Vector4();
	Vector4(const float a_x, const float a_y, const float a_z, const float a_w);

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
	Vector4 operator+ (const Vector4& a_rhs) const;
	Vector4 operator- (const Vector4& a_rhs) const;
	Vector4 operator* (const float a_rhs) const;
	Vector4 operator/ (const float a_rhs) const;

	// Corresponding op=
	Vector4& operator+= (const Vector4& a_rhs);
	Vector4& operator-= (const Vector4& a_rhs);
	Vector4& operator*= (const float a_rhs);
	Vector4& operator/= (const float a_rhs);
	bool operator== (const Vector4& a_rhs) const;
	
	//** UTILIZATION **//
	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector4 normalised() const;

	float dot(const Vector4& a_vec4) const;
	static float dot(const Vector4& a_vec4_1, const Vector4& a_vec4_2);

	Vector4 cross(const Vector4& a_vec4) const;
	static Vector4 cross(const Vector4& a_vec3_1, const Vector4& a_vec3_2);
};

Vector4 operator* (const float a_lhs, const Vector4& a_rhs);

#endif // !_VECTOR_4_
