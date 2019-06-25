//Vector 3.h
//class represents a set of carteasean coordinates
//for use in 3 dimentional systems
#pragma once

#ifndef _VECTOR_3_

#define _VECTOR_3_

class Vector_3
{
public:
	//math data for Vector_3
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
	Vector_3();
	Vector_3(const float a_x, const float a_y, const float a_z);
	//allows direct data access by overloading 
	//returns reference to indexed data
	float& operator[] (const int index);

	//castng operators overloading
	//changable version
	operator float* ();
	//read only version
	operator const float* () const;
	//allows addition between Vector 3
	Vector_3 operator + (const Vector_3& other) const;
	//allows subtraction between Vector 3
	Vector_3 operator - (const Vector_3& other) const;
	//allows multiplacation between Vector 3
	Vector_3 operator * (float scalar) const;
	//allows division between Vector 3
	Vector_3 operator / (float scalar) const;



	//allows the use of the += operator between Vector 3
	Vector_3& operator += (const Vector_3& a_rhs);
	//allows the use of the -= operator between Vector 3
	Vector_3& operator -= (const Vector_3& a_rhs);
	//allows the use of the *= operator between Vector 3
	Vector_3& operator *= (const float a_rhs);
	//allows the use of the /= operator between Vector 3
	Vector_3& operator /= (const float a_rhs);

	float square_magnitude() const;
	//finds the size of a Vector
	float magnitude() const;

	//normalises the Vector to allow comparison between other Vectors
	void normalise();
	Vector_3 normalised() const;

	//allows checking of equivelentcy
	bool operator == (const Vector_3& a_rhs);

	//finds the dot product which gives you the amount something has been moved in a direction
	float dot(const Vector_3& a_rhs) const;
	static float dot(const Vector_3& a_lhs, const Vector_3& a_rhs);

	//gives another Vector 4 which has a right angle to both the inputs
	Vector_3 cross(const Vector_3& a_rhs) const;
	static Vector_3 cross(const Vector_3& a_lhs, const Vector_3& a_rhs);
};

Vector_3 operator*(const float a_lhs, const Vector_3& a_rhs);


#endif // VECTOR_3_
