#include "behaviour.h"



behaviour::behaviour(const Vector_2& position, agent* newthing) :currentPos(position), thing(newthing)
{

}


behaviour::~behaviour()
{
}

void behaviour::update(float deltaTime)
{
	switch (state)
	{
	case behaviourState::SEEK:
		seek(deltaTime);
			break;
	case behaviourState::FLEE:
		seek(deltaTime);
		break;
	case behaviourState::WANDER:
		seek(deltaTime);
		break;
	}
}

void behaviour::flee(float deltaTime)
{

}

void behaviour::wander(float deltaTime)
{

}

void behaviour::seek(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	input->getMouseXY(&targetMouseX, &targetMouseY);
	mousePos = { float(targetMouseX),float(targetMouseY) };
	targetPos = mousePos;
	Vector_2 direction = (mousePos - currentPos);
	float uuu = direction.normalised().magnitude();
	uuu * deltaTime * 100;
}

void behaviour::updateDirection(float deltaTime)
{

}

void behaviour::setState(behaviourState newState)
{

}