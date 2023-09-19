#pragma once
#include "../../GameManager/ResourceManager.h"

class IPState {
public:
	enum STATE
	{
		RUN,
		IDLE,
		JUMP1,
		JUMP2,
		FALL1,
		FALL2,
		FALL3,
		FALL4,
		FALL5,
		FALL6,
		READY,
		SNULL,
	};

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
};
