#pragma once
#include "Vector_2.h"
#include "colliders.h"
class line : public colliders
{
public:
	static const Vector_2 defaultNormal;

	line(const Vector_2& newNormal = defaultNormal,
		const float newDistance = 0.0f);
	
	const Vector_2 getNormal() const; // provides the value of the normal
	void setNormal(const Vector_2 newNormal); // allows changes in the normal

	const float getDistance() const; // the length of hte line
	void setDistance(const float newDistance); // allows the legth of the line ot change

private:
	Vector_2 m_normal{ 1.0f,0.0f };
	float m_distance = 0.0f;

};

