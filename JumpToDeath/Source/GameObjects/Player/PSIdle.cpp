#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_Player = player;
	m_Player->checkDirection = 1;
	m_Player->checkJump = 1;
	m_Player->checkFall = 1;
	m_Player->checkPriorState = 1;
}

void PSIdle::Init()
{
	m_Animation = new Animation("Idle/tile", 11, 0.07f);
}

void PSIdle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Player->changeNextState(RUN);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_Animation->setScale(-1, 1);
		}
		else
		{
			m_Animation->setScale(1, 1);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_Player->changeNextState(READY);
	}


	if (m_Player->checkDirection == -1)
	{
		m_Animation->setScale(-1, 1);
	}
	else if(m_Player->checkDirection == 1)
	{
		m_Animation->setScale(1, 1);;
	}
	else
	{
		if (m_Player->checkJump == -1)
		{
			m_Animation->setScale(-1, 1);
		}
		else
		{
			m_Animation->setScale(1, 1);;
		}
	}

	m_Player->resetCollision();
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}


