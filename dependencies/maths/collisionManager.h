#pragma once
#include "circle.h"
#include "aabb.h"
#include "line.h"

class collisionManager
{
public:
	static bool circleCircle(const circle& firstCircle, const circle& secondCircle);

	static bool aabbAabb(const aabb& firstAabb, const aabb& secondAabb);

	static bool circleAabb(const circle& theCircle, const aabb& theAabb);

	static bool lineCircle(const line& theLine, const circle& theCircle);

	static bool lineAabb(const line& theLine, const aabb& theAabb);

private:
	static Vector_2 clamp(const Vector_2& circlePosition, const Vector_2 min, const Vector_2 max);
};

