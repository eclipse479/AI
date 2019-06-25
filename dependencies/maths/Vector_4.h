//Vector 4.h
//class represents a set of carteasean coordinates
//for use in 3 dimentional systems
#pragma once

#ifndef _VECTOR_4_

#define _VECTOR_4_

class Vector_4
{
public:
	//math data for Vector_4
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
	Vector_4();
	Vector_4(const float a_x, const float a_y, const float a_z, const float a_w);
	//allows direct data access by overloading 
	//returns reference to indexed data
	float& operator[] (const int index);

	//castng operators overloading
	//changable version
	operator float* ();
	//read only version
	operator const float* () const;

	//allows addition between Vector 4
	Vector_4 operator + (const Vector_4& other) const;
	//allows subtraction between Vector 4
	Vector_4 operator - (const Vector_4& other) const;
	//allows multiplacation between Vector 4
	Vector_4 operator * (float scalar) const;
	//allows division between Vector 4
	Vector_4 operator / (float scalar) const;



	//allows the use of the += operator between Vector 4
	Vector_4& operator += (const Vector_4& a_rhs);
	//allows the use of the -= operator between Vector 4
	Vector_4& operator -= (const Vector_4& a_rhs);
	//allows the use of the *= operator between Vector 4
	Vector_4& operator *= (const float a_rhs);
	//allows the use of the /= operator between Vector 4
	Vector_4& operator /= (const float a_rhs);

	float square_magnitude() const;
	//finds the size of a Vector
	float magnitude() const;

	//normalises the Vector to allow comparison between other Vectors
	void normalise();
	Vector_4 normalised() const;

	//allows checking of equivelentcy
	bool operator == (const Vector_4& a_rhs);

	//finds the dot product which gives you the amount something has been moved in a direction
	float dot(const Vector_4& a_rhs) const;
	static float dot(const Vector_4& a_lhs, const Vector_4& a_rhs);

	//gives another Vector 4 which has a right angle to all the inputs
	Vector_4 cross(const Vector_4& a_rhs) const;
	static Vector_4 cross(const Vector_4& a_lhs, const Vector_4& a_rhs);
};

Vector_4 operator*(const float a_lhs, const Vector_4& a_rhs);


#endif // VECTOR_4_
