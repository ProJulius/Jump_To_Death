#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"

class GSSetting : public GameStateBase {
public:
	GSSetting();
	virtual ~GSSetting();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Text m_Title;
	std::list<GameButton*> m_ListBtn;
	ParallexBackground m_Background;
};