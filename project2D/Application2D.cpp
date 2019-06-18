#include "Application2D.h"
#include <iostream>


Application2D::Application2D() 
{

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	setVSync(true);
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	hero = new aie::Texture("../bin/textures/hero.png");
	bigBad = new aie::Texture("../bin/textures/bigBadBoss.png");
	background = new aie::Texture("../bin/textures/dungeon Room.png");
	heart = new aie::Texture("../bin/textures/heart.png");
	bones = new aie::Texture("../bin/textures/skullBones.png");
	orbital = new aie::Texture("../bin/textures/sanicBlade.png");
	m_graph = new graph<Vector2>();


	//recursive magic to build graphs

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			m_graph->createNode({ (j + 1.0f)*spacing, (i + 1.0f)*spacing });
		}
	}

	//Horizontals

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width-1; ++j)
		{
			m_graph->createEdge(
				m_graph->m_nodes[i*width + j],
				m_graph->m_nodes[i*width + j + 1]);
		}
	}
	//Verticals

	for (int i = 0; i < height-1; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			m_graph->createEdge(
				m_graph->m_nodes[i*width + j],
				m_graph->m_nodes[(i+1)*width + j]);
		}
	}

	m_timer = 0;
	return true;
}

void Application2D::shutdown() 
{
	delete m_font;
	delete m_2dRenderer;
	delete hero;
	delete bigBad;
	delete background;
	delete heart;
	delete bones;
	delete orbital;
}

void Application2D::update(float deltaTime) 
{
	aie::Input* input = aie::Input::getInstance();
	

	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);
	//moves the camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		camPosY += 500.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		camPosY -= 500.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		camPosX -= 500.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		camPosX += 500.0f * deltaTime;
	}
	
	m_2dRenderer->setCameraPos(camPosX, camPosY);

	int mouseX = 0;
	int mouseY = 0;

	input->getMouseXY(&mouseX, &mouseY);
	
	float shortestDistance = FLT_MAX;
	node<Vector2>* closestNode = nullptr;
	//-------------------------RIGHT CLICK -------------------------------
	if (input->wasMouseButtonPressed(1)) 
	{
		Vector2 mousePosition = { float(mouseX),float(mouseY) };

		for (auto& a_node : m_graph->m_nodes)
		{
			float distance = (mousePosition - a_node->m_data).magnitude();
			if (distance < shortestDistance)
			{
				shortestDistance = distance;
				closestNode = a_node;
			}
		}

		m_graph->removeNode(closestNode);
	}
	// ----------------------------LEFT CLICK------------------------------
		if (input->wasMouseButtonPressed(0)) 
		{
			Vector2 mousePosition = { float(mouseX),float(mouseY) };

			for (auto& a_node : m_graph->m_nodes)
			{
				float distance = (mousePosition - a_node->m_data).magnitude();
				if (distance < shortestDistance)
				{
					shortestDistance = distance;
					closestNode = a_node;
				}
			}
			selectionQueue.push(closestNode);
			closestNode->hasBeenSelected = true;
			if (selectionQueue.size() > 2)
			{
				selectionQueue.pop();
			}

			if (selectionQueue.size() == 2)
			{
				m_graph->calculatePathAStar(selectionQueue.front(), selectionQueue.back());
			}
		}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	//m_2dRenderer->drawSprite(background, 925, 575, 2100, 1200,0,100);
	
	//draws the grid
	for (auto & a_edge : m_graph->m_edges)
	{
		if (a_edge->hasBeenTraced)
		{
			m_2dRenderer->setRenderColour(.5, 0, .5);
			node<Vector2>* A = a_edge->m_nodes[0];
			node<Vector2>* B = a_edge->m_nodes[1];
			m_2dRenderer->drawLine(A->m_data.x, A->m_data.y, B->m_data.x, B->m_data.y,5);
		}
		else
		{
			m_2dRenderer->setRenderColour(1, .45f, .5f);
			node<Vector2>* A = a_edge->m_nodes[0];
			node<Vector2>* B = a_edge->m_nodes[1];
			m_2dRenderer->drawLine(A->m_data.x, A->m_data.y, B->m_data.x, B->m_data.y,5);
		}
	}
	m_2dRenderer->setRenderColour(1, 1, 1);
	//draws the circles for all of the nodes
	for (auto & a_node : m_graph->m_nodes)
	{
		if (a_node->hasBeenSelected) // if a node has been selected colour it green
		{
			m_2dRenderer->drawSprite(bigBad, a_node->m_data.x, a_node->m_data.y, 50,50);
		}
		else // else colour it yellow
		{
	
			m_2dRenderer->drawSprite(heart,a_node->m_data.x, a_node->m_data.y, 25,25);
		}
	}
	//draws the blue dot
	if (selectionQueue.size() > 0)
	{
		m_2dRenderer->setRenderColour(0, 0, 1);
		m_2dRenderer->drawSprite(hero,selectionQueue.front()->m_data.x, selectionQueue.front()->m_data.y, 50,50);
	}
	//draws the red dot
	if (selectionQueue.size() > 1)
	{
		m_2dRenderer->setRenderColour(1, 0, 0);
		m_2dRenderer->drawSprite(hero,selectionQueue.back()->m_data.x, selectionQueue.back()->m_data.y, 50,50);
	}
	//draws the path
	for (int i =0 ; i < int(m_graph->path.size())-1 ;++i)
	{
		m_2dRenderer->setRenderColour(1, 1, 0);
		node<Vector2>* A = m_graph->path[i];
		node<Vector2>* B = m_graph->path[i + 1];
		m_2dRenderer->drawLine(A->m_data.x, A->m_data.y, B->m_data.x, B->m_data.y,5);
	}

	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 10, 1100 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 10, 1100 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}