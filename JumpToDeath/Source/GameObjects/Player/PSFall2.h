#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSFall2 :public IPState
{
public:
	PSFall2(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);


private:
	IPlayer* m_Player;
	Animation* m_Animation;
	Block* m_Block;
};
