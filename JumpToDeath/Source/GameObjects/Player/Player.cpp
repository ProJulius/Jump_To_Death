#include "Player.h"
#include "PSRun.h"
#include "PSIdle.h"
#include "PSJump1.h"
#include "PSJump2.h"
#include "PSFall1.h"
#include "PSFall2.h"
#include "PSFall3.h"
#include "PSFall4.h"
#include "PSFall5.h"
#include "PSFall6.h"
#include "PSReady.h"


Player::Player()
{ 
	m_nextState = IPState::SNULL;
	m_runState = new PSRun(this);
	m_idleState = new PSIdle(this);
	m_jumpState1 = new PSJump1(this);
	m_jumpState2 = new PSJump2(this);
	m_fallState1 = new PSFall1(this);
	m_fallState2 = new PSFall2(this);
	m_fallState3 = new PSFall3(this);
	m_fallState4 = new PSFall4(this);
	m_fallState5 = new PSFall5(this);
	m_fallState6 = new PSFall6(this);
	m_readyState = new PSReady(this);
	m_currentState = m_idleState;
}

Player::~Player()
{
	if (m_runState != nullptr)
	{
		delete m_runState;
	}
	if (m_idleState != nullptr)
	{
		delete m_idleState;
	}
	if (m_jumpState1 != nullptr)
	{
		delete m_jumpState1;
	}
	if (m_jumpState2 != nullptr)
	{
		delete m_jumpState2;
	}
	if (m_fallState1 != nullptr)
	{
		delete m_fallState1;
	}
	if (m_fallState2 != nullptr)
	{
		delete m_fallState2;
	}
	if (m_fallState3 != nullptr)
	{
		delete m_fallState3;
	}
	if (m_fallState4 != nullptr)
	{
		delete m_fallState4;
	}
	if (m_fallState5 != nullptr)
	{
		delete m_fallState5;
	}
	if (m_fallState6 != nullptr)
	{
		delete m_fallState6;
	}
	if (m_readyState != nullptr)
	{
		delete m_readyState;
	}
	m_currentState = nullptr;
}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}



void Player::Init()
{
	m_runState->Init();
	m_idleState->Init();
	m_jumpState1->Init();
	m_jumpState2->Init();
	m_fallState1->Init();
	m_fallState2->Init();
	m_fallState3->Init();
	m_fallState4->Init();
	m_fallState5->Init();
	m_fallState6->Init();
	m_readyState->Init();

	m_HitBox = new HitBox(sf::Vector2i(38, 80)); 
	m_HitBox->setPosition(672, 7478);
	//m_HitBox->setPosition(672, 700);
	m_HitBox->Init(sf::Vector2f(140, 100));
}

void Player::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);

}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}


void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::IDLE:
			m_currentState = m_idleState;
			break;
		case IPState::JUMP1:
			m_currentState = m_jumpState1;
			break;
		case IPState::JUMP2:
			m_currentState = m_jumpState2;
			break;
		case IPState::FALL1:
			m_currentState = m_fallState1;
			break;
		case IPState::FALL2:
			m_currentState = m_fallState2;
			break;
		case IPState::FALL3:
			m_currentState = m_fallState3;
			break;
		case IPState::FALL4:
			m_currentState = m_fallState4;
			break;
		case IPState::FALL5:
			m_currentState = m_fallState5;
			break;
		case IPState::FALL6:
			m_currentState = m_fallState6;
			break;
		case IPState::READY:
			m_currentState = m_readyState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
	}
}