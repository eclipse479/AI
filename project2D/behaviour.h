#pragma once
#include <vector>
#include "Application2D.h"
#include "Vector_2.h"
#include "Input.h"

class agent;

enum class behaviourState
{
	WANDER,
	SEEK,
	FLEE
};

class behaviour
{
public:
	behaviour(const Vector_2& position, agent* newthing);
	~behaviour();

	void update(float deltaTime);

	void flee(float deltaTime);

	void wander(float deltaTime);

	void seek(float deltaTime);

	void updateDirection(float deltaTime);

	void setState(behaviourState newState);
protected:
	int targetMouseX;
	int targetMouseY;
	Vector_2 currentPos;
	Vector_2 targetPos;
	Vector_2 mousePos;
	agent* thing;
	behaviourState state;
};

