#include "agent.h"



agent::agent()
{
}


agent::~agent()
{
}

void agent::update(float deltaTime)
{

}
void agent::draw(aie::Renderer2D* m_2Drenderer, aie::Texture* image)
{
	m_2Drenderer->drawSprite(image, position.x, position.y, 100, 100);
}
void agent::addBehaviour(behaviour* newBehaviour)
{

}
