#include "circle.h"
#include <cmath>

const float circle::defaultRadius = 5.0f;

circle::circle(const Vector_2& newPosition /*= Vector_2()*/,
			   const float newRadius /* = defaultRadius*/) :
	           m_position(newPosition),
			   m_radius(newRadius),
	colliders(shape::circle)
{
}


const float circle::getRadius() const
{
	return m_radius;
}
void circle::set_radius(const float newRadius)
{
	m_radius = abs(newRadius);
}

const Vector_2 circle::getPosition() const
{
	return m_position;
}
void circle::setPosition(const Vector_2& newPosition)
{
	m_position = newPosition;
}


