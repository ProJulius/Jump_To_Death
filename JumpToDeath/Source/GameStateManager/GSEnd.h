#pragma once
#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"

class GSEnd : public GameStateBase {
public:
	GSEnd();
	virtual ~GSEnd();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:;
	   std::list<GameButton*> m_ListBtn;
	   sf::Text m_Title;
	   ParallexBackground m_Background;
};