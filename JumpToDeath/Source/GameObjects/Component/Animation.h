#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Animation : public Sprite
{
private:
	vector<Texture*> textures;
	int currentFrame;
	float frameTime;
	int frameNum;
	float timer;
public:
	Animation();
	Animation(string name, int frameNum, float frameTime);
	void Update(float deltaTime);
	Texture* getTexture();
};