#include "gameObject.h"
#include "Application2D.h"
#include "collisionManager.h"


gameObject::gameObject(aie::Texture* image, const Vector_2& a_position, float newWidth, float newHieght, const float rotationZ, const float newRadius, const float spin/* = 0.0f*/, const float orbit/* = 0.0f*/, float newHealth /*= 1*/)
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


gameObject::~gameObject()
{
}


void gameObject::update(const float deltaTime)
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

void gameObject::move(const float deltaTime)
{
	speed += acceleration * deltaTime;
	aie::Input* input = aie::Input::getInstance();
	float accelerationHold = 350;
	float spinHold = 5.0f;
	int mouseX = 0;
	int mouseY = 0;

	input->getMouseXY(&mouseX, &mouseY);
	
	Vector_2 mousePos = { float(mouseX), float(mouseY) };
	Vector_2 direction = { mouseX - localPositionMatrix.forward.x,mouseY - localPositionMatrix.forward.y };
	Vector_2 velocity = direction.normalised();
	setAcceleation(accelerationHold);

	//if (velocity < 0.995f)
	//{
	//	if (velocity < 1 && velocity >= 0)
	//	{
	//		setSpin(spinHold);
	//	}
	//	else if (velocity > -1 && velocity < 0)
	//	{
	//		setSpin(-spinHold);
	//	}
	//	else
	//	{
	//		setSpin(0.0f);
	//	}
	//}
	localPositionMatrix.forward += localPositionMatrix.up * speed*deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		std::cout << "hi\n";
	}
}

matrix_3x3 const &gameObject::getGlobalMatrix() const
{
	return globalPositionMatrix;
}
Vector_2 const gameObject::getPosition() const
{
	return	position;
}

void gameObject::setPosition(const Vector_2& setPosition)
{
	position.x = setPosition.x;
	position.y = setPosition.y;
}

void gameObject::setLocalPosition(const Vector_2& newLocalPosition)
{
	position.x = newLocalPosition.x;
	position.y = newLocalPosition.y;
}
void gameObject::setRotation(const float rotation)
{
	currentRotation = rotation;
}
void gameObject::setGlobalRotation(const float rotation)
{
	 
}

void gameObject::setParent(gameObject* theParent)
{
	parent = theParent;
}
	
float gameObject::getWidth()
{
	return width;
}
float gameObject::getHeight()
{
	return height;
}

float gameObject::getSpeed()
{
	return speed;
}
void gameObject::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

float gameObject::getSpin()
{
	return spinSpeed;
}
void gameObject::setSpin(float newSpin)
{
	spinSpeed = newSpin;
}

float gameObject::getAcceleation()
{
	return acceleration;
}
void gameObject::setAcceleation(float newAcceleration)
{
	acceleration = newAcceleration;
}

void gameObject::drawPlanet(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawCircle(globalPositionMatrix.forward.x, globalPositionMatrix.forward.y, radius);
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalPositionMatrix, width, height);
}

bool gameObject::circleCircleCollision(gameObject* other)
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

float gameObject::getHealth()
{
	return health;
}
void  gameObject::modifyHealth(float modifier)
{
	health += modifier;
}
void gameObject::setHealth(float newHealth)
{
	health = newHealth;
}

bool gameObject::boxcollision(gameObject* other)
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
void gameObject::setWall(float posX, float posY, float width, float height)
{
	wall = { {posX,posY}, {width,height} };
}

float gameObject::getX()
{
	return globalPositionMatrix.forward.x;
}
float gameObject::getY()
{
	return globalPositionMatrix.forward.y;
}

aie::Texture* gameObject::getTexture()
{
	return texture;
}
void gameObject::changeTexture(aie::Texture* newImage)
{
	texture = newImage;
}

float gameObject::getRadius()
{
	return radius;

}

void gameObject::changeSpeed(float spin, float orbit)
{
	spinSpeed = spin;
	orbitSpeed = orbit;
}

void gameObject::setAlive(bool state)
{
	alive = state;
}
bool gameObject::isAlive()
{
	return alive;
}
