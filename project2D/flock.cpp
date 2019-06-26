#include "flock.h"

flock::flock()
{

}

flock::~flock()
{
}

void flock::createBoids(int number)
{
	for (int i = 0; i < number-1; i++)
	{
		listOfBoids.push_back(boid(this));
	}
}

void flock::draw(aie::Renderer2D* renderer)
{
		renderer->setRenderColour(0, 1, 0);

	for (boid thisBoid : listOfBoids)
	{
		thisBoid.draw(renderer);
	}
}

void flock::update(float deltaTime)
{
	for (boid& thisBoid : listOfBoids)
	{
		thisBoid.update(deltaTime);
	}
}