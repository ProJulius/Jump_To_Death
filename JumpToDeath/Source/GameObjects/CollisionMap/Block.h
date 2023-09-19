#pragma once
#include "../../GameManager/ResourceManager.h"
#include "CollisionManager.h";

class Block {
private:
	HitBox m_HitBox;
public:
	Block();
	Block(std::string link, sf::Vector2f size, sf::Vector2f position);
	~Block();
	void Render(sf::RenderWindow* window);
	CollisionManager GetCollider() { return CollisionManager(m_HitBox); }
	
};