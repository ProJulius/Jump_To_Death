#include "GSIntro.h"
#include <fstream>

GSIntro::GSIntro()
{
	m_currentTime = 0.f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	std::string name;
	sf::Texture* texture = DATA->getTexture("Logo");
	m_Logo.setTexture(*texture);
	m_Logo.setScale(0.15, 0.15);
	m_Logo.setPosition(screenWidth / 2, screenHeight / 2);
	m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
}

void GSIntro::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= 1.5) {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(m_Logo);
}