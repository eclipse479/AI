#include "matrix_3x3.h"



matrix_3x3::matrix_3x3(const float m_00/* = 1.0f*/, const float m_01/* = 0.0f*/, const float m_02/* = 0.0f*/, //collum 1
					   const float m_10/* = 0.0f*/, const float m_11/* = 1.0f*/, const float m_12/* = 0.0f*/, //collum 2
					   const float m_20/* = 0.0f*/, const float m_21/* = 0.0f*/, const float m_22/* = 1.0f*/) : //collum 3
	multiDimension{	m_00, m_01, m_02, m_10, m_11, m_12, m_20, m_21, m_22}
{

}


matrix_3x3::matrix_3x3(const Vector_3& a_right, const Vector_3& a_up, const Vector_3& a_forward)
{

}


matrix_3x3::operator float* ()
{
	return singleDimension;
}
//read only version
matrix_3x3::operator const float* () const
{
	return singleDimension;
}

Vector_3& matrix_3x3::operator [] (int index)
{
	return axes[index];

}

// const access for read-only
const Vector_3& matrix_3x3::operator [] (const int index) const
{
	return axes[index];
}

matrix_3x3 matrix_3x3::operator * (const matrix_3x3& a_rhs) const
{
	
	return
	{
		multiDimension[0][0] * a_rhs.multiDimension[0][0] + multiDimension[1][0] * a_rhs.multiDimension[0][1] + multiDimension[2][0] * a_rhs.multiDimension[0][2] ,
		multiDimension[0][1] * a_rhs.multiDimension[0][0] + multiDimension[1][1] * a_rhs.multiDimension[0][1] + multiDimension[2][1] * a_rhs.multiDimension[0][2] ,
		multiDimension[0][2] * a_rhs.multiDimension[0][0] + multiDimension[1][2] * a_rhs.multiDimension[0][1] + multiDimension[2][2] * a_rhs.multiDimension[0][2] ,
			
		multiDimension[0][0] * a_rhs.multiDimension[1][0] + multiDimension[1][0] * a_rhs.multiDimension[1][1] + multiDimension[2][0] * a_rhs.multiDimension[1][2] ,
		multiDimension[0][1] * a_rhs.multiDimension[1][0] + multiDimension[1][1] * a_rhs.multiDimension[1][1] + multiDimension[2][1] * a_rhs.multiDimension[1][2] ,
		multiDimension[0][2] * a_rhs.multiDimension[1][0] + multiDimension[1][2] * a_rhs.multiDimension[1][1] + multiDimension[2][2] * a_rhs.multiDimension[1][2] ,
	
		multiDimension[0][0] * a_rhs.multiDimension[2][0] + multiDimension[1][0] * a_rhs.multiDimension[2][1] + multiDimension[2][0] * a_rhs.multiDimension[2][2] ,
		multiDimension[0][1] * a_rhs.multiDimension[2][0] + multiDimension[1][1] * a_rhs.multiDimension[2][1] + multiDimension[2][1] * a_rhs.multiDimension[2][2] ,
		multiDimension[0][2] * a_rhs.multiDimension[2][0] + multiDimension[1][2] * a_rhs.multiDimension[2][1] + multiDimension[2][2] * a_rhs.multiDimension[2][2] ,
	};
}

Vector_3 matrix_3x3::operator*(const Vector_3& a_rhs) const
{
	return
	{
		multiDimension[0][0] * a_rhs[0] + multiDimension[1][0] * a_rhs[1] + multiDimension[2][0] * a_rhs[2],
		multiDimension[0][1] * a_rhs[0] + multiDimension[1][1] * a_rhs[1] + multiDimension[2][1] * a_rhs[2],
		multiDimension[0][2] * a_rhs[0] + multiDimension[1][2] * a_rhs[1] + multiDimension[2][2] * a_rhs[2]
	};
}


void matrix_3x3::setRotateX(float x_rotation)
{
	singleDimension[4] = cos(x_rotation);
	singleDimension[5] = sin(x_rotation);
	singleDimension[7] = -sin(x_rotation);
	singleDimension[8] = cos(x_rotation);
}
void matrix_3x3::setRotateY(float y_rotation)
{
	singleDimension[0] = cos(y_rotation);
	singleDimension[2] = -sin(y_rotation);
	singleDimension[6] = sin(y_rotation);
	singleDimension[8] = cos(y_rotation);
}
void matrix_3x3::setRotateZ(float z_rotation)
{
	singleDimension[0] = cos(z_rotation);
	singleDimension[1] = sin(z_rotation);
	singleDimension[3] = -sin(z_rotation);
	singleDimension[4] = cos(z_rotation);
}