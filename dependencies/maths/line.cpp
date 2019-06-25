#include "line.h"
#include <limits>

const Vector_2 line::defaultNormal = { 0.0f,1.0f };

line::line(const Vector_2& newNormal/* = Vector_2()*/,
	const float newDistance/* = 0.0f*/) :
	m_normal(newNormal),
	m_distance(newDistance),
	colliders(shape::line)
{
	setNormal(m_normal);
}

const Vector_2 line::getNormal() const
{
	return m_normal;
}
void line::setNormal(const Vector_2 newNormal)
{
	if (m_normal.magnitude() < std::numeric_limits<float>::min())
	{
	m_normal = defaultNormal;
	}
	else
	{
		m_normal.normalise();
	}
}

const float line::getDistance() const
{
	return m_distance;
}
void line::setDistance(const float newDistance)
{
	m_distance = newDistance;
}
