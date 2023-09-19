#pragma once
#include "../../GameManager/ResourceManager.h"
#include "Block.h"
#include <vector>
#include <iostream>
#include <cstring>
class Map
{
private:
	std::vector <std::vector<int>> map_ID;
	std::vector <std::vector<Block*>> map_Texture;
	std::vector<Block*> m_Block;
public:
	Map();
	~Map();
	void Init();
	void Render(sf::RenderWindow* window);
	std::vector <Block*> getBlock();
	std::vector <Texture> m_BackGround;
};