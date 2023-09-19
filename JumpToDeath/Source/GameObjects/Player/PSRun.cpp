#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
	m_Player = player;
}

void PSRun::Init()
{
	m_Animation = new Animation("Run/tile", 12, 0.07f);
}

void PSRun::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Player->checkFall = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		m_Animation->setScale(-1, 1);
		m_Player->checkDirection = -1;
		m_Player->checkJump = -1;
		if (m_Player->checkCollision() == 0)
		{
			m_Player->velocity.y = 0;
			m_Player->changeNextState(FALL2);
			return;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		m_Animation->setScale(1, 1);
		m_Player->checkDirection = 1;
		m_Player->checkJump = 1;
		if (m_Player->checkCollision() == 0)
		{
			m_Player->velocity.y = 0;
			m_Player->changeNextState(FALL2);
			return;
		}
	}
	else
	{
		m_Player->changeNextState(IDLE);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	
}

void PSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}