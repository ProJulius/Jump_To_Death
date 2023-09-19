#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	Layer* layer;
	std::string path = "Background layer/";

	layer = new Layer();
	layer->Init(path + "Sky", 50);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "BG_Decor", 130);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "Middle_Decor", 150);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "Foreground", 175);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "Ground", 200);
	m_Background.push_back(layer);

}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}