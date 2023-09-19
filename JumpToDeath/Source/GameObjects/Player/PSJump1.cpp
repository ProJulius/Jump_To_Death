#include "PSJump1.h"

PSJump1::PSJump1(IPlayer* player)
{
	m_Player = player;
}

void PSJump1::Init()
{
	m_Animation = new Animation("Jump1/tile", 1, 5.f);
	m_Player->velocity.y = sqrt(981 * 2.0f * 200.f * m_Player->jumpValue);
}

void PSJump1::Update(float deltaTime)
{
	
	m_Animation->Update(deltaTime);
	m_Player->velocity.y -= 981 * deltaTime;
	if (m_Player->checkDirection == -1)
	{
		m_Player->getHitBox()->move(-400.f * deltaTime, -m_Player->velocity.y * deltaTime);	
	}
	else if (m_Player->checkDirection == 1)
	{
		m_Player->getHitBox()->move(400.f * deltaTime, -m_Player->velocity.y * deltaTime);
	}

	if (m_Player->checkDirection == -1)
	{
		m_Animation->setScale(-1, 1);
	}
	else
	{
		m_Animation->setScale(1, 1);
	}


	if (m_Player->checkCollision() == -1 || m_Player->checkCollision() == 1)
	{
		m_Player->changeNextState(FALL3);	
	}
	else if (m_Player->checkCollision() == -2)
	{
		m_Player->changeNextState(FALL5);
	}
	else
	{
		if (m_Player->velocity.y <= 0)
		{
			m_Player->changeNextState(FALL1);
		}
		else
		{
			m_Player->resetCollision();
		}
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSJump1::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

