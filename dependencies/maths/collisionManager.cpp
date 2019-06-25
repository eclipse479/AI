#include "collisionManager.h"
#include <cmath>


bool collisionManager::circleCircle(const circle& firstCircle, const circle& secondCircle)
{
	Vector_2 displacement = firstCircle.getPosition() - secondCircle.getPosition();
	float sumRadius = firstCircle.getRadius() + secondCircle.getRadius();

	return(displacement.magnitude() < sumRadius);
}

bool collisionManager::aabbAabb(const aabb& firstAabb, const aabb& secondAabb)
{
	return !(firstAabb.getMax().x < secondAabb.getMin().x ||
		 	 firstAabb.getMin().x > secondAabb.getMax().x ||
			 firstAabb.getMax().y < secondAabb.getMin().y ||
			 firstAabb.getMin().y > secondAabb.getMax().y);
}

bool collisionManager::circleAabb(const circle& theCircle, const aabb& theAabb)
{
	Vector_2 clampedCenter = clamp(theCircle.getPosition(), theAabb.getMin(), theAabb.getMax());
	Vector_2 displacement = clampedCenter - theCircle.getPosition();
	return (displacement.magnitude() < theCircle.getRadius());
}

bool collisionManager::lineCircle(const line& theLine, const circle& theCircle)
{
	float positonDotNormal = theCircle.getPosition().dot(theLine.getNormal());
	float distance = positonDotNormal - (theLine.getDistance() + theCircle.getRadius());
	return (distance < 0);
}

bool collisionManager::lineAabb(const line& theLine, const aabb& theAabb)
{
	//#1 loop each corner and dot product the distance

	Vector_2 extents = 0.5f * theAabb.getExtents().right();
	Vector_2 extentsNegX = Vector_2{ -theAabb.getExtents().x,theAabb.getExtents().y };

	float dotExtents = extents.dot(theLine.getNormal());
	float dotNegExtentsX = extentsNegX.dot(theLine.getNormal());

	float radius = fmaxf(fabsf(dotExtents), fabsf(dotNegExtentsX));

	circle projection{ theAabb.getPosition(), radius };

	return lineCircle(theLine, projection);
}


Vector_2 collisionManager::clamp(const Vector_2& aVector2, const Vector_2 min, const Vector_2 max)
{
	return { fminf(fmaxf(aVector2.x,min.x),max.x),
		 	 fminf(fmaxf(aVector2.y,min.y),max.y )};
}
