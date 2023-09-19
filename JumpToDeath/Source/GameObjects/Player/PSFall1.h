#pragma once
#include "IPState.h"
#include "IPlayer.h"


class PSFall1 :public IPState
{
public:
	PSFall1(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPlayer* m_Player;
	Animation* m_Animation;

};
