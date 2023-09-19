#include "PSReady.h"

PSReady::PSReady(IPlayer* player)
{
	m_Player = player;

}

void PSReady::Init()
{
	m_Animation = new Animation("Ready/tile", 1, 5.f);
	m_Player->jumpValue = 0.f;
	isPressing = false;
	m_Player->checkDirection = 1;
	m_Player->checkJump = 1;
}

void PSReady::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_Player->checkDirection = -1;
			m_Player->checkJump = -1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_Player->checkDirection = 1;
			m_Player->checkJump = 1;
		}
		else m_Player->checkDirection = 0;

		isPressing = true;
		if (isPressing) m_Player->jumpValue += 0.04f;
		if (m_Player->jumpValue >= 1.6f)
		{
			m_Player->jumpValue = 1.6f;
			m_Player->velocity.y = sqrt(981 * 2.0f * 200.f * m_Player->jumpValue);
			if (m_Player->checkDirection != 0) m_Player->changeNextState(JUMP1);
			else m_Player->changeNextState(JUMP2);
			isPressing = false;
		}
	}
	else
	{
		m_Player->velocity.y = sqrt(981 * 2.0f * 200.f * m_Player->jumpValue);
		if (m_Player->checkDirection != 0) m_Player->changeNextState(JUMP1);
		else m_Player->changeNextState(JUMP2);
		isPressing = false;
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSReady::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}


