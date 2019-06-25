#include "matrix_4x4.h"


matrix_4x4::matrix_4x4(const float m_00/* = 1.0f*/, const float m_01/* = 0.0f*/, const float m_02/* = 0.0f*/, const float m_03/* = 0.0f*/,  // collum 1
					   const float m_10/* = 0.0f*/, const float m_11/* = 1.0f*/, const float m_12/* = 0.0f*/, const float m_13/* = 0.0f*/, // collum 2
					   const float m_20/* = 0.0f*/, const float m_21/* = 0.0f*/, const float m_22/* = 1.0f*/, const float m_23/* = 0.0f*/,// collum 3
					   const float m_30/* = 0.0f*/, const float m_31/* = 0.0f*/, const float m_32/* = 0.0f*/, const float m_33/* = 1.0f*/) : //collum 3
	multiDimension{ m_00, m_01, m_02,m_03, m_10, m_11, m_12,m_13, m_20, m_21, m_22,m_23,m_30,m_31,m_32,m_33 }
{

}


matrix_4x4::matrix_4x4(const Vector_4& a_right, const Vector_4& a_up, const Vector_4& a_forward, const Vector_4& a_position)
{

}

matrix_4x4::operator float* ()
{
	return singleDimension;
}
//read only version
matrix_4x4::operator const float* () const
{
	return singleDimension;
}


Vector_4& matrix_4x4::operator [] (int index)
{
	return axes[index];
}

// const access for read-only
const Vector_4& matrix_4x4::operator [] (const int index) const
{
	return axes[index];
}

matrix_4x4 matrix_4x4::operator * (const matrix_4x4& a_rhs) const
{

	return
	{
		multiDimension[0][0] * a_rhs.multiDimension[0][0] + multiDimension[1][0] * a_rhs.multiDimension[0][1] + multiDimension[2][0] * a_rhs.multiDimension[0][2] + multiDimension[3][0] * a_rhs.multiDimension[0][3] ,
		multiDimension[0][1] * a_rhs.multiDimension[0][0] + multiDimension[1][1] * a_rhs.multiDimension[0][1] + multiDimension[2][1] * a_rhs.multiDimension[0][2] + multiDimension[3][1] * a_rhs.multiDimension[0][3] ,
		multiDimension[0][2] * a_rhs.multiDimension[0][0] + multiDimension[1][2] * a_rhs.multiDimension[0][1] + multiDimension[2][2] * a_rhs.multiDimension[0][2] + multiDimension[3][2] * a_rhs.multiDimension[0][3] ,
		multiDimension[0][3] * a_rhs.multiDimension[0][0] + multiDimension[1][3] * a_rhs.multiDimension[0][1] + multiDimension[2][3] * a_rhs.multiDimension[0][2] + multiDimension[3][3] * a_rhs.multiDimension[0][3] ,
																																												   
		multiDimension[0][0] * a_rhs.multiDimension[1][0] + multiDimension[1][0] * a_rhs.multiDimension[1][1] + multiDimension[2][0] * a_rhs.multiDimension[1][2] + multiDimension[3][0] * a_rhs.multiDimension[1][3] ,
		multiDimension[0][1] * a_rhs.multiDimension[1][0] + multiDimension[1][1] * a_rhs.multiDimension[1][1] + multiDimension[2][1] * a_rhs.multiDimension[1][2] + multiDimension[3][1] * a_rhs.multiDimension[1][3] ,
		multiDimension[0][2] * a_rhs.multiDimension[1][0] + multiDimension[1][2] * a_rhs.multiDimension[1][1] + multiDimension[2][2] * a_rhs.multiDimension[1][2] + multiDimension[3][2] * a_rhs.multiDimension[1][3],
		multiDimension[0][3] * a_rhs.multiDimension[1][0] + multiDimension[1][3] * a_rhs.multiDimension[1][1] + multiDimension[2][3] * a_rhs.multiDimension[1][2] + multiDimension[3][3] * a_rhs.multiDimension[1][3] ,
																																												   
		multiDimension[0][0] * a_rhs.multiDimension[2][0] + multiDimension[1][0] * a_rhs.multiDimension[2][1] + multiDimension[2][0] * a_rhs.multiDimension[2][2] + multiDimension[3][0] * a_rhs.multiDimension[2][3] ,
		multiDimension[0][1] * a_rhs.multiDimension[2][0] + multiDimension[1][1] * a_rhs.multiDimension[2][1] + multiDimension[2][1] * a_rhs.multiDimension[2][2] + multiDimension[3][1] * a_rhs.multiDimension[2][3] ,
		multiDimension[0][2] * a_rhs.multiDimension[2][0] + multiDimension[1][2] * a_rhs.multiDimension[2][1] + multiDimension[2][2] * a_rhs.multiDimension[2][2] + multiDimension[3][2] * a_rhs.multiDimension[2][3],
		multiDimension[0][3] * a_rhs.multiDimension[2][0] + multiDimension[1][3] * a_rhs.multiDimension[2][1] + multiDimension[2][3] * a_rhs.multiDimension[2][2] + multiDimension[3][3] * a_rhs.multiDimension[2][3] ,
																																												   
		multiDimension[0][0] * a_rhs.multiDimension[3][0] + multiDimension[1][0] * a_rhs.multiDimension[3][1] + multiDimension[2][0] * a_rhs.multiDimension[3][2] + multiDimension[3][0] * a_rhs.multiDimension[3][3] ,
		multiDimension[0][1] * a_rhs.multiDimension[3][0] + multiDimension[1][1] * a_rhs.multiDimension[3][1] + multiDimension[2][1] * a_rhs.multiDimension[3][2] + multiDimension[3][1] * a_rhs.multiDimension[3][3] ,
		multiDimension[0][2] * a_rhs.multiDimension[3][0] + multiDimension[1][2] * a_rhs.multiDimension[3][1] + multiDimension[2][2] * a_rhs.multiDimension[3][2] + multiDimension[3][2] * a_rhs.multiDimension[3][3],
		multiDimension[0][3] * a_rhs.multiDimension[3][0] + multiDimension[1][3] * a_rhs.multiDimension[3][1] + multiDimension[2][3] * a_rhs.multiDimension[3][2] + multiDimension[3][3] * a_rhs.multiDimension[3][3] ,

	};
}

Vector_4 matrix_4x4::operator*(const Vector_4& a_rhs) const
{
	return
	{
		multiDimension[0][0] * a_rhs[0] + multiDimension[1][0] * a_rhs[1] + multiDimension[2][0] * a_rhs[2] + multiDimension[3][0] * a_rhs[3],
		multiDimension[0][1] * a_rhs[0] + multiDimension[1][1] * a_rhs[1] + multiDimension[2][1] * a_rhs[2] + multiDimension[3][1] * a_rhs[3],
		multiDimension[0][2] * a_rhs[0] + multiDimension[1][2] * a_rhs[1] + multiDimension[2][2] * a_rhs[2] + multiDimension[3][2] * a_rhs[3],
		multiDimension[0][3] * a_rhs[0] + multiDimension[1][3] * a_rhs[1] + multiDimension[2][3] * a_rhs[2] + multiDimension[3][3] * a_rhs[3]
	};
}

void matrix_4x4::setRotateX(float x_rotation)
{
	singleDimension[5] = cos(x_rotation);
	singleDimension[6] = sin(x_rotation);
	singleDimension[9] = -sin(x_rotation);
	singleDimension[10] = cos(x_rotation);
}
void matrix_4x4::setRotateY(float y_rotation)
{
	singleDimension[0] = cos(y_rotation);
	singleDimension[2] = -sin(y_rotation);
	singleDimension[8] = sin(y_rotation);
	singleDimension[10] = cos(y_rotation);
}
void matrix_4x4::setRotateZ(float z_rotation)
{
	singleDimension[0] = cos(z_rotation);
	singleDimension[1] = sin(z_rotation);
	singleDimension[4] = -sin(z_rotation);
	singleDimension[5] = cos(z_rotation);
}