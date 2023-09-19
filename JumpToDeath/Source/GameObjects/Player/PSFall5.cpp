#include "PSFall5.h"

PSFall5::PSFall5(IPlayer* player)
{
	m_Player = player;
}

void PSFall5::Init()
{
	m_Animation = new Animation("Fall5/tile", 1, 5.f);
}

void PSFall5::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (m_Player->velocity.y <= 1000.f)
	{
		m_Player->velocity.y += 981 * deltaTime;
	}

	if (m_Player->checkDirection == -1)
	{
		m_Player->getHitBox()->move(-400.f * deltaTime, m_Player->velocity.y * deltaTime);
	}
	else if (m_Player->checkDirection == 1)
	{
		m_Player->getHitBox()->move(400.f * deltaTime, m_Player->velocity.y * deltaTime);
	}

	
	if (m_Player->checkCollision() == -1 || m_Player->checkCollision() == 1)
	{
		m_Player->checkPriorState = -1;
		m_Player->changeNextState(FALL4);
	}


	if (m_Player->checkDirection == -1)
	{
		m_Animation->setScale(-1, 1);
	}
	else
	{
		m_Animation->setScale(1, 1);
	}


	if (m_Player->checkCollision() == 2)
	{
		m_Player->getHitBox()->setPosition(m_Player->getHitBox()->getPosition().x, m_Player->getHitBox()->getPosition().y);
		m_Player->resetCollision();
		m_Player->jumpValue = 0.f;
		m_Player->changeNextState(IDLE);
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSFall5::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}



