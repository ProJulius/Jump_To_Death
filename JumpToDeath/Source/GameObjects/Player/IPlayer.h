#pragma once
#include "IPState.h"
#include"../CollisionMap/Map.h"

class IPlayer
{
	
public:
	
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	
	
	Vector2f velocity;
	int checkDirection;
	int checkJump;
	int checkFall;
	float jumpValue;
	int checkPriorState;
	
	CollisionManager* check;
	int checkCollision() { return check->checkColl(); };
	void resetCollision() { return check->ResetColl(); };
};