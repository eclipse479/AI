#pragma once
#include <vector>
#include "Vector_2.h"
#include "boid.h"
#include <list>

class boid;

class flock
{
public:

	flock();
	~flock();

	std::vector<boid> listOfBoids;
	Vector_2 cursorPosition;
	void createBoids(int number);
	float attract = 0;
	void draw(aie::Renderer2D* renderer);
	void update(float deltaTime);
};

