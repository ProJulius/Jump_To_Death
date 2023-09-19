#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"
#include "../GameObjects/Player/Player.h"
#include "../GameObjects/CollisionMap/Map.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	Player m_Player;
	Map m_Map;
	std::vector <Block*> m_Block;
	sf::View playerView;
	float upperLimit, lowerLimit;
	bool checkColl;
};