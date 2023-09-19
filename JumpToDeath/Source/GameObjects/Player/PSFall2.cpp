#include "PSFall2.h"

PSFall2::PSFall2(IPlayer* player)
{
	m_Player = player;
}

void PSFall2::Init()
{
	m_Animation = new Animation("Fall2/tile", 1, 5.f);
}

void PSFall2::Update(float deltaTime)
{

	m_Animation->Update(deltaTime);

	if (m_Player->velocity.y <= 1000.f)
	{
		m_Player->velocity.y += 981 * deltaTime;
	}

	m_Player->getHitBox()->move(0, m_Player->velocity.y * deltaTime);

	if (m_Player->checkJump == -1)
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
		
		m_Player->jumpValue = 0.f;
		m_Player->changeNextState(IDLE);
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSFall2::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}