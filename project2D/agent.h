#pragma once
#include "Application2D.h"
#include "Vector_2.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "behaviour.h"

class agent
{
public:
	agent();
	virtual ~agent();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* m_2Drenderer, aie::Texture* image);
	void addBehaviour(behaviour* newBehaviour);

	// Movement functions
	void SetPosition(Vector_2 newposition) { position = newposition; }
	Vector_2 GetPosition() { return position; }

void SetVelocity(Vector_2 newVelocity) { velocity = newVelocity; }
Vector_2 GetVelocity() { return velocity; }

protected:

	std::vector<behaviour*> behaviourList;
	Vector_2 position;
	Vector_2 velocity;
};

