#include "GSPlay.h"

GSPlay::GSPlay()
{
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	m_Player.Init();
	m_Map.Init();
	playerView.setSize(screenWidth, screenHeight);
	upperLimit = 0;
	lowerLimit = screenHeight;
}

void GSPlay::Update(float deltaTime)
{
	if (m_Player.getHitBox()->getPosition().y <= upperLimit) {
		playerView.setCenter(756,upperLimit - screenHeight / 2);
		upperLimit = upperLimit - screenHeight;
		lowerLimit = upperLimit + screenHeight;
		
	}
	else if (m_Player.getHitBox()->getPosition().y >= lowerLimit) {
		playerView.setCenter(756, lowerLimit + screenHeight / 2);
		lowerLimit = lowerLimit + screenHeight;
		upperLimit = lowerLimit - screenHeight;
	}

	m_Player.Update(deltaTime); 

	m_Block = m_Map.getBlock();

	bool checkFall = false;
	for (auto block : m_Block)
	{
		block->GetCollider().checkCollider(m_Player.GetCollider());
		if (block->GetCollider().checkCollider(m_Player.GetCollider()))
			checkFall = true;
	}
	if (checkFall == false && m_Player.checkFall == 0)
	{
		m_Player.resetCollision();
		checkFall = true;
		m_Player.checkFall = 1;
	}

	//1300 296
	if (m_Player.getHitBox()->getPosition().x >= 1300 && m_Player.getHitBox()->getPosition().y == 296)
	{
		playerView.setCenter(screenWidth/2, screenHeight/2);
		GSM->ChangeState(StateTypes::CHAMPION);
	}
	
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->setView(playerView);
	m_Map.Render(window);
	m_Player.Render(window);
} 