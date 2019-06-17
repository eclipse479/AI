#pragma once
#include "Vector2.h"
#include "colliders.h"
class aabb : public colliders
{
public:
	static const Vector2 defaultExtents; // gives the defaut size of the extents

	aabb(const Vector2& newPosition = Vector2(), 
		 const Vector2& newExtents = defaultExtents);

	const Vector2 getPosition() const; // retrieves the position of the aabb
	void setPosition(const Vector2& newPosition); // changes the position of the aabb

	const Vector2 getExtents() const; // retrieves the extent size of the aabb
	void setExtents(const Vector2& newExtents); // changes the aabb extent sizes

	float getWidth() const; 
	float getHeight() const;

	const Vector2 getMax() const;
	const Vector2 getMin() const;
private:
	Vector2 m_position { 0.0f,0.0f };
	
	union 
	{
		Vector2 m_extents;
		struct
		{
			float width;
			float height;
		};

	};
};

