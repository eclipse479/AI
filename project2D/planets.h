#pragma once
#include "matrix_3x3.h"
#include "Vector_2.h"
#include "circle.h"
#include "aabb.h"
#include "Texture.h"
#include "Renderer2D.h"
#include <iostream>

class planets
{
public:
	planets() {}
	planets(aie::Texture* image, const Vector_2& a_position, float newWidth, float newHieght, const float rotationZ, const float newRadius, const float spin = 0.0f, const float orbit = 0.0f, float newHealth = 1);
	~planets();

	void update(const float deltaTime);

	const matrix_3x3& getGlobalMatrix() const;
	const Vector_2 getPosition() const;

	void setPosition(const Vector_2& setPposition);
	void setLocalPosition(const Vector_2& newLocalPosition);

	void setRotation(const float rotation);
	void setGlobalRotation(const float rotation);

	void setParent(planets* theParent);
	aie::Texture* getTexture();

	float getWidth();
	float getHeight();

	float getSpeed();
	void setSpeed(float newSpeed);

	float getSpin();

	void setSpin(float newSpin);

	float getAcceleation();
	void setAcceleation(float newAcceleration);

	void move(const float deltaTime);


	void drawPlanet(aie::Renderer2D* m_2dRenderer);

	bool circleCircleCollision(planets* other);
	bool boxcollision(planets* other);

	void setWall(float posX, float posY, float width, float height);

	void setAlive(bool state);;
	bool isAlive();

	float getHealth();
	void modifyHealth(float modifier);
	void setHealth(float newHealth);

	float getX();
	float getY();
	float getRadius();
	void changeTexture(aie::Texture* newImage);

	void changeSpeed(float spin, float orbit);

protected:
	matrix_3x3 localPositionMatrix;
	matrix_3x3 globalPositionMatrix;

	Vector_2 position;


	float speed;
	float acceleration;
	float maxSpeed = 750;
	float currentRotation; //this is in radians
	float orbitSpeed;	   //this is in radians / second
	float spinSpeed;	   //this is in radians / second
	float width;
	float height;
	float radius;

	circle hitBox;
	aabb wall;

	float aabbX;
	float aabbY;
	float aabbWidth;
	float aabbHeight;

	Vector_2 size;
	aie::Texture* texture;

	planets* parent;
	float health;
	bool alive = true;
};

