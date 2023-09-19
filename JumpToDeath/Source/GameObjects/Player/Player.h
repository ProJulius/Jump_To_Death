#pragma once
#include "IPlayer.h"


class Player :public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	CollisionManager GetCollider() { return CollisionManager(*m_HitBox); }

	HitBox* getHitBox();
private:

	void performStateChange();
	HitBox* m_HitBox;

	IPState::STATE m_nextState;

	IPState* m_currentState;
	IPState* m_runState;
	IPState* m_idleState;
	IPState* m_jumpState1;
	IPState* m_jumpState2;
	IPState* m_fallState1;
	IPState* m_fallState2;
	IPState* m_fallState3;
	IPState* m_fallState4;
	IPState* m_fallState5;
	IPState* m_fallState6;
	IPState* m_readyState;

};