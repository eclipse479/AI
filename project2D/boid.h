#pragma once
#include "Vector_2.h"
#include "Renderer2D.h"
#include <cmath>
#include "flock.h"
//CHANGE THESE AT SOME POINT
#define BOID_SPEED 5.0f
#define NEIGHBOUR_RADIUS 120.0f
#define SEPARATION_FORCE 2.0f
#define COHERANT_FORCE 5.0f
#define ALIGNMENT_FORCE 0.2f
#define BOID_COUNT 50.0f
#define CIRCLE_RADIUS 5

class flock;

class boid
{
public:
	boid(flock* parentFlock);
	boid();
	void update(float deltaTime);

	void draw(aie::Renderer2D* renderer);

	Vector_2 position;

	Vector_2 velocity;

	void applyForce(Vector_2 force);


	flock* theFlock;
};