// @brief Vector3.h
// Class represents a pair of cartesian coordinates
// for use in two dimentional game systems

#pragma once

#ifndef _VECTOR_3_
#define _VECTOR_3_

class Vector3
{
	// @brief
	// Critical math data for a vector 3
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float data[3];
	};

	Vector3();
	Vector3(const float a_x, const float a_y, const float a_z);

	/* @brief Subscript operator overloading to allow direct
			  data access
	   @param index of the data member
	   @return reference to indexed data member
	*/
	float& operator[](const int a_index);

	/* @brief Casting mutable float*
			  operator overloading
	*/
	operator float* ();

	/* @brief Casting read only float*
			  operator overloading
	*/
	operator const float* () const;

	//** CONSTRUCTION ZONE **//
	Vector3 operator+ (const Vector3& a_rhs) const;
	Vector3 operator- (const Vector3& a_rhs) const;
	Vector3 operator* (const float a_rhs) const;
	Vector3 operator/ (const float a_rhs) const;

	// Corresponding op=
	Vector3& operator+= (const Vector3& a_rhs);
	Vector3& operator-= (const Vector3& a_rhs);
	Vector3& operator*= (const float a_rhs);
	Vector3& operator/= (const float a_rhs);
	bool operator== (const Vector3& a_rhs) const;

	//** UTILIZATION **//
	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector3 normalised() const;

	float dot(const Vector3& a_vec3) const;
	static float dot(const Vector3& a_vec3_1, const Vector3& a_vec3_2);

	Vector3 cross(const Vector3& a_vec3) const;
	static Vector3 cross(const Vector3& a_vec3_1, const Vector3& a_vec3_2);
};

Vector3 operator* (const float a_lhs, const Vector3& a_rhs);

#endif // !_VECTOR_3_
