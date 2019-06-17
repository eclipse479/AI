#pragma once
#include "Vector2.h"
#include "colliders.h"
class circle :
	public colliders
{
public:
	static const float defaultRadius; 
	circle(const Vector2& newPosition = Vector2(), // constructor
		   const float newRadius = defaultRadius);

	const float getRadius() const;
	void set_radius(const float newRadius);

	const Vector2 getPosition() const;
	void setPosition(const Vector2& newPosition);



private:


	float m_radius = 0.0f;
	Vector2 m_position{ 0.0f,0.0f };
};

