#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"

class GSMenu : public GameStateBase {
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	std::list<GameButton*> m_ListBtn;
	sf::Text m_Title;
	ParallexBackground m_Background;
};