#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Vector_2.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <list>
#include "graph.h"
#include "heap.h"
#include "gameObject.h"
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
	aie::Texture*		alone;
	aie::Texture*		boi;
	aie::Font*			m_font;

	gameObject*			zambie;

	graph<Vector_2>*		m_graph;

	int spacing = 60;
	int width = 20;
	int height = 11;

	std::queue<node<Vector_2>*>	selectionQueue;
	float m_timer;
};