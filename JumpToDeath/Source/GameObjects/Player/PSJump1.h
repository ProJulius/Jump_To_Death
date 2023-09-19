#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSJump1 :public IPState
{
public:
	PSJump1(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	IPlayer* m_Player;
	Animation* m_Animation;
	int check;
};
