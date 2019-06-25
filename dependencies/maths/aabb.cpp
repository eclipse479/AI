#include "aabb.h"
#include <cmath>
const Vector_2 aabb::defaultExtents = { 5.0f,5.0f }; // defaulst extent size

//the constructor
aabb::aabb(const Vector_2& newPosition/* = Vector_2()*/,
	const Vector_2& newExtents /*= defaultExtents*/):
	m_position(newPosition),
	m_extents(newExtents),
	colliders(shape::aabb)
{

}

const Vector_2 aabb::getPosition() const
{
	return m_position;
}
void aabb::setPosition(const Vector_2& newPosition)
{
	m_position = newPosition;
}

const Vector_2 aabb::getExtents() const
{
	return m_extents;
}
void aabb::setExtents(const Vector_2& newExtents)
{
	m_extents = { abs(newExtents.x), abs(newExtents.y) };
}

float aabb::getWidth() const
{
	return width;
}
float aabb::getHeight() const
{
	return height;
}

const Vector_2 aabb::getMax() const
{
	return m_position + 0.5f*m_extents;
}
const Vector_2 aabb::getMin() const
{
	return m_position - 0.5f*m_extents;
}