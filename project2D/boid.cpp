#include "boid.h"
#include <random>

boid::boid(flock* parentFlock)
{
	this->theFlock = parentFlock;

	position = Vector_2(float((rand() % 1200)), float((rand() % 720)));

	velocity = Vector_2(float((rand() % 11) - 5), float((rand() % 11) - 5));
	
	red = ((rand() % 10)*0.2);
	green = ((rand() % 10)*0.2);
	blue = ((rand() % 10)*0.2);

	if (velocity.magnitude() <= 0.00001f)
	{
		velocity = Vector_2(BOID_SPEED, 0.0f);
	}
	else
	{
		velocity.normalise();
		velocity *= BOID_SPEED;
	}
}

boid::boid()
{
}

void boid::update(float deltaTime)
{
	//create list------------------------------------------------------------------
	std::vector<boid*> neighbours;
	for (boid& thisBoid : theFlock->listOfBoids)
	{
		if (&thisBoid == this)
		{
			continue;
		}
		if ((thisBoid.position - position).magnitude() < NEIGHBOUR_RADIUS)
		{
			neighbours.push_back(&thisBoid);
		}
	}

	//-------------------World center keeps the boids inside the circle---------------------------------------------------------
	Vector_2 worldCenter = { 900,550 };
	Vector_2 toCenter = worldCenter - this->position;
	float distanceOutsideCircle = (toCenter.magnitude()-500);

	if (distanceOutsideCircle > 0.0f)
	{
		toCenter.normalise();
		toCenter *= (CIRCLE_FORCE * distanceOutsideCircle);
		this->applyForce(toCenter);
	}


	//---------SEPARATION FORCE---------------------------------------------------------------------------
	Vector_2 separationForce;
	for (boid* thisBoid : neighbours)
	{
		Vector_2 fromNeighbourToYou = position - thisBoid->position;
		fromNeighbourToYou.normalise();
		fromNeighbourToYou *= SEPARATION_FORCE;
		separationForce += fromNeighbourToYou;
	}

	this->applyForce(separationForce);

	//---------------------------------COHESION---------------------------------
	if (neighbours.size() > 0)
	{
		Vector_2 averageNeighbourPos;
		for (boid* thisBoid : neighbours)
		{
			averageNeighbourPos += thisBoid->position;
		}
		averageNeighbourPos /= neighbours.size();
		Vector_2 fromUsToAverage = averageNeighbourPos - this->position;
		fromUsToAverage.normalise();
		fromUsToAverage *= COHERANT_FORCE;
		this->applyForce(fromUsToAverage);
	}


	//average neighbourhood velocity ALSO ALIGNMENT------------------------------------------------------------------
	if (neighbours.size() > 0)
	{
		Vector_2 averageNeighbourVel;
		for (boid* thisBoid : neighbours)
		{
			averageNeighbourVel += thisBoid->velocity;
		}
		averageNeighbourVel /= neighbours.size();

		this->applyForce(averageNeighbourVel * ALIGNMENT_FORCE);
	}

	//cursor stuff------------------------------------------------------------------
	//Vector_2 holdToCursor = theFlock->cursorPosition - this->position;
	//
	//float forceMagnitude = holdToCursor.magnitude();

	//forceMagnitude -= .1f;
	//forceMagnitude = theFlock->attract * 10000 / (forceMagnitude*forceMagnitude +1000.0f);

	//holdToCursor.normalise();
	//
	//this->applyForce(holdToCursor * .2f);

	//----------------------------------------------------
	if (velocity.magnitude() <= 0.00001f)
	{
		velocity = Vector_2(BOID_SPEED, 0.0f);
	}
	else
	{
		velocity.normalise();
		velocity *= BOID_SPEED;
	}

	position += velocity;
}

void boid::draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(red, green, blue);
	renderer->drawCircle(position.x, position.y, 5);
}

void boid::applyForce(Vector_2 force)
{
	velocity += force;
}