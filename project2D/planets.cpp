#include "planets.h"
#include "Application2D.h"
#include "collisionManager.h"

planets::planets(aie::Texture* image, const Vector_2& a_position, float newWidth, float newHieght, const float rotationZ, const float newRadius, const float spin/* = 0.0f*/, const float orbit/* = 0.0f*/, float newHealth /*= 1*/)
	: texture(image), position(a_position), width(newWidth), height(newHieght), currentRotation(rotationZ), radius(newRadius), spinSpeed(spin), orbitSpeed(orbit),health(newHealth)
{
	parent = nullptr;
	localPositionMatrix.setRotateZ(currentRotation);
	localPositionMatrix.forward = { a_position.x, a_position.y, 1 };
	speed = 0;
	acceleration = 0;
	texture = image;
	width = newWidth;
	height = newHieght;
	radius = newRadius;
	hitBox = { position, circle::defaultRadius };
	health = newHealth;
	spinSpeed = spin;
	orbitSpeed = orbit;
	//thing = { { position.x,(position.y - 100) }, {100,100} };
}


planets::~planets()
{
}


void planets::update(const float deltaTime)						
{
	if (speed > maxSpeed)
	{
		speed = maxSpeed;
	}
	else if (speed < -maxSpeed)
	{
		speed = -maxSpeed;
	}

	matrix_3x3 rotation;
	rotation.setRotateZ(deltaTime * spinSpeed);
	localPositionMatrix = localPositionMatrix * rotation;
	rotation.setRotateZ(deltaTime * orbitSpeed);
	localPositionMatrix = rotation * localPositionMatrix;


	if (parent)
	{
		globalPositionMatrix = parent->globalPositionMatrix * localPositionMatrix;
	}
	else
	{
		globalPositionMatrix = localPositionMatrix;
	}

	hitBox.setPosition({ globalPositionMatrix.forward.x, globalPositionMatrix.forward.y });
	hitBox.set_radius(radius);
}

void planets::move(const float deltaTime)
{
	speed += acceleration * deltaTime;
	aie::Input* input = aie::Input::getInstance();
	float accelerationHold = 350;
	float spinHold = 5.0f;
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		setAcceleation(accelerationHold);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		setAcceleation(-accelerationHold+100);
	}
	else if (speed < 0)
	{
		setAcceleation(100);
	}
	else if (speed > 0)
	{
		setAcceleation(-100);
	}
	else
	{
		setAcceleation(0.0f);
	}

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		setSpin(spinHold);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		setSpin(-spinHold);
	}
	else
	{
		setSpin(0.0f);
	}

	localPositionMatrix.forward += localPositionMatrix.up * speed*deltaTime;
}

matrix_3x3 const &planets::getGlobalMatrix() const
{
	return globalPositionMatrix;
}
Vector_2 const planets::getPosition() const
{
	return	position;
}

void planets::setPosition(const Vector_2& setPosition)				
{
	position.x = setPosition.x;
	position.y = setPosition.y;
}

void planets::setLocalPosition(const Vector_2& newLocalPosition)	
{
	position.x = newLocalPosition.x;
	position.y = newLocalPosition.y;
}
void planets::setRotation(const float rotation)
{
	currentRotation = rotation;
}
void planets::setGlobalRotation(const float rotation) 
{
	 
}

void planets::setParent(planets* theParent)
{
	parent = theParent;
}


float planets::getWidth()
{
	return width;
}
float planets::getHeight()
{
	return height;
}

float planets::getSpeed()
{
	return speed;
}
void planets::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

float planets::getSpin()
{
	return spinSpeed;
}
void planets::setSpin(float newSpin)
{
	spinSpeed = newSpin;
}


float planets::getAcceleation()
{
	return acceleration;
}
void planets::setAcceleation(float newAcceleration)
{
	acceleration = newAcceleration;
}

void planets::drawPlanet(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawCircle(globalPositionMatrix.forward.x, globalPositionMatrix.forward.y, radius);
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalPositionMatrix, width, height);
}

bool planets::circleCircleCollision(planets* other)
{
	if (collisionManager::circleCircle(hitBox, other->hitBox))
	{
		return true;
	}
	else
	{
		return false;
	}
}





float planets::getHealth()
{
	return health;
}
void  planets::modifyHealth(float modifier)
{
	health += modifier;
}
void planets::setHealth(float newHealth)
{
	health = newHealth;
}

bool planets::boxcollision(planets* other)
{
	if (collisionManager::circleAabb(hitBox, other->wall))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void planets::setWall(float posX, float posY, float width, float height)
{
	wall = { {posX,posY}, {width,height} };
}



float planets::getX()
{
	return globalPositionMatrix.forward.x;
}
float planets::getY()
{
	return globalPositionMatrix.forward.y;
}

aie::Texture* planets::getTexture()
{
	return texture;
}float planets::getRadius()
{
	return radius;

}
void planets::changeTexture(aie::Texture* newImage)
{
	texture = newImage;
}

void planets::changeSpeed(float spin, float orbit)
{
	spinSpeed = spin;
	orbitSpeed = orbit;
}

void planets::setAlive(bool state)
{
	alive = state;
}
bool planets::isAlive()
{
	return alive;
}
