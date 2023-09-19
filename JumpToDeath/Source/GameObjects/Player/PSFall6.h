#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSFall6 :public IPState
{
public:
	PSFall6(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPlayer* m_Player;
	Animation* m_Animation;

};
