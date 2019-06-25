#pragma once
#include "Vector_3.h"
#include <cstdlib>
class matrix_3x3
{
public:
	
	union
	{
		struct
		{
			float xAxis[3];
			float yAxis[3];
			float zAxis[3];
		};

		float singleDimension[9]; // holds data in a single array
		float multiDimension[3][3]; // holds data in 2 dimensional array

		struct
		{
			Vector_3 right;
			Vector_3 up;
			Vector_3 forward;
		};

	Vector_3 axes[3];
	};

	//changable version
	operator float* ();
	//read only version
	operator const float* () const;
	//constructor
	matrix_3x3(const float m_00 = 1.0f, const float m_01 = 0.0f, const float m_02 = 0.0f,  // collum 1
				const float m_10 = 0.0f, const float m_11 = 1.0f, const float m_12 = 0.0f, // collum 2
				const float m_20 = 0.0f, const float m_21 = 0.0f, const float m_22 = 1.0f);// collum 3

	//allows access thorugh different constructor
	matrix_3x3(const Vector_3& a_right, const Vector_3& a_up, const Vector_3& a_forward);
	//referecnce access so it can be modified
	Vector_3& operator [] (const int index); // retrives 
	//const access for read only
	const Vector_3& operator [] (int index) const;

	// multiplacation with another matrix
	matrix_3x3 operator * (const matrix_3x3& a_rhs) const; 
	// multiplacation with a Vector_3
	Vector_3 operator*(const Vector_3& a_rhs) const; 


	//rotates the matrix in a way that moves on the given axis
	void setRotateX(float x_rotation);
	void setRotateY(float y_rotation);
	void setRotateZ(float z_rotation);
};

