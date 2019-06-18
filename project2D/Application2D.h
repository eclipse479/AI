#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <list>
#include "graph.h"
#include "heap.h"
#include <queue>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;

	aie::Texture*		hero;
	aie::Texture*		background;
	aie::Texture*		bigBad;
	aie::Texture*		heart;
	aie::Texture*		bones;
	aie::Texture*		orbital;
	aie::Font*			m_font;

	graph<Vector2>*		m_graph;

	int spacing = 40;
	int width = 31;
	int height = 17;

	std::queue<node<Vector2>*>	selectionQueue;
	float m_timer;
};