#pragma once
#include "Vector2.h"
#include "colliders.h"
class line : public colliders
{
public:
	static const Vector2 defaultNormal;

	line(const Vector2& newNormal = defaultNormal,
		const float newDistance = 0.0f);
	
	const Vector2 getNormal() const; // provides the value of the normal
	void setNormal(const Vector2 newNormal); // allows changes in the normal

	const float getDistance() const; // the length of hte line
	void setDistance(const float newDistance); // allows the legth of the line ot change

private:
	Vector2 m_normal{ 1.0f,0.0f };
	float m_distance = 0.0f;

};

