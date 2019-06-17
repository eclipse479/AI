#pragma once
#include "aabb.h"
#include "circle.h"
#include "line.h"
#include <cmath>

class collision_manager
{
public:
	static bool circle_circle(const circle& a_circle_A, const circle& a_circle_B); // Manages circle to circle collision
	static bool aabb_aabb(const aabb& a_aabb_A, const aabb& a_aabb_B); // Manages aabb to aabb collision
	static bool aabb_circle(const aabb& a_aabb, const circle& a_circle); // Manages aabb to circle collision
	static bool circle_line(const circle& a_circle, const line& a_line); // Manages circle to line collision
	static bool aabb_line(const aabb& a_aabb, const line& a_line); // Manages aabb to line collision

private:
	// Clamps aabb collider
	static Vector2 clamp(const Vector2& a_vector_2, 
						 const Vector2& a_min, 
						 const Vector2& a_max);
};

