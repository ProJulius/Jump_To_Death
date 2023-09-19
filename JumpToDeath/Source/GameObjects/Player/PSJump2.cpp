#include "PSJump2.h"

PSJump2::PSJump2(IPlayer* player)
{
	m_Player = player;
}

void PSJump2::Init()
{
	m_Animation = new Animation("Jump2/tile", 1, 5.f);
	m_Player->velocity.y = sqrt(981 * 2.0f * 200.f * m_Player->jumpValue);
}

void PSJump2::Update(float deltaTime)
{

	m_Animation->Update(deltaTime);

	m_Player->velocity.y -= 981 * deltaTime;

	m_Player->getHitBox()->move(0, -m_Player->velocity.y * deltaTime);

	if (m_Player->checkJump == -1)
	{
		m_Animation->setScale(-1, 1);
	}
	else
	{
		m_Animation->setScale(1, 1);
	}

	

	if (m_Player->velocity.y <= 0 || m_Player->checkCollision() == -2)
	{
		m_Player->changeNextState(FALL2);
	}
	else
	{
		m_Player->resetCollision();
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSJump2::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

