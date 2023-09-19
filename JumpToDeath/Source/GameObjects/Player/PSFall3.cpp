#include "PSFall3.h"

PSFall3::PSFall3(IPlayer* player)
{
	m_Player = player;
}

void PSFall3::Init()
{
	m_Animation = new Animation("Fall3/tile", 1, 5.f);
}

void PSFall3::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Player->velocity.y -= 981 * deltaTime;

	if (m_Player->checkDirection == -1)
	{
		m_Player->getHitBox()->move(350.f * deltaTime, -m_Player->velocity.y * deltaTime);
	}
	else if (m_Player->checkDirection == 1)
	{
		m_Player->getHitBox()->move(-350.f * deltaTime, -m_Player->velocity.y * deltaTime);
	}

	if (m_Player->velocity.y <= 0)
	{
		m_Player->checkPriorState = -1;
		m_Player->changeNextState(FALL4);
		m_Player->resetCollision();
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

void PSFall3::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}



