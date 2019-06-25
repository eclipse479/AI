#include "colliders.h"



colliders::colliders(shape a_shape) : m_shape(a_shape)
{
}


const colliders::shape colliders::getShape() const 
{
	return m_shape;
}