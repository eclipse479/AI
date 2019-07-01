#pragma once
#include "Vector_2.h"
#include "Renderer2D.h"
#include <cmath>
#include "flock.h"
//CHANGE THESE AT SOME POINT
#define BOID_SPEED 5.0f
#define NEIGHBOUR_RADIUS 50.0f
#define SEPARATION_FORCE 50.0f
#define COHERANT_FORCE 20.0f
#define ALIGNMENT_FORCE 25.0f
#define BOID_COUNT 500
#define CIRCLE_FORCE 50.0f

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
	float red;
	float green;
	float blue;

	flock* theFlock;
};