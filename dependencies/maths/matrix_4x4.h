#pragma once
#include "Vector_4.h"
#include <cstdlib>
class matrix_4x4
{
public:

	union // only allows one data piece in the union
	{
		struct
		{
			float xAxis[3];
			float yAxis[3];
			float zAxis[3];
			float wAxis[3];
		};

		float singleDimension[16]; // holds the data in a single array
		float multiDimension[4][4]; // holds data in a 2 dimensional array

		struct
		{
			Vector_4 right;
			Vector_4 up;
			Vector_4 forward;
			Vector_4 position;
		};

		Vector_4 axes[4]; 
	};

	//changable version
	operator float* ();
	//read only version
	operator const float* () const;
	//constructor
	matrix_4x4(const float m_00 = 1.0f, const float m_01 = 0.0f, const float m_02 = 0.0f, const float m_03 = 0.0f,  // collum 1
			  const float m_10 = 0.0f, const float m_11 = 1.0f, const float m_12 = 0.0f, const float m_13 = 0.0f, // collum 2
			  const float m_20 = 0.0f, const float m_21 = 0.0f, const float m_22 = 1.0f, const float m_23 = 0.0f,// collum 3
			  const float m_30 = 0.0f, const float m_31 = 0.0f, const float m_32 = 0.0f, const float m_33 = 1.0f);// collum 4

	//allows access thorugh different constructor
	matrix_4x4(const Vector_4& a_right, const Vector_4& a_up, const Vector_4& a_forward, const Vector_4& a_position);
	//referecnce access so it can be modified
	Vector_4& operator [] (const int index);
	//const access for read only
	const Vector_4& operator [] (int index) const;

	// allows multiplacation with another 4x4 matrix
	matrix_4x4 operator * (const matrix_4x4& a_rhs) const; 
	// allows multiplacation with a Vector 4
	Vector_4 operator*(const Vector_4& a_rhs) const; 

	//rotates the matrix in a way that moves on the given axis
	void setRotateX(float x_rotation);
	void setRotateY(float y_rotation);
	void setRotateZ(float z_rotation);
};

