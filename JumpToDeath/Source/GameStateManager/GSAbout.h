#pragma once
#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"

class GSAbout : public GameStateBase {
public:
	GSAbout();
	virtual ~GSAbout();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<GameButton*> m_ListBtn;
	sf::Text m_Title;
	sf::Text m_Instruction;
	ParallexBackground m_Background;
};