#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(string name, int frameNum, float frameTime)
{
	this->frameNum = frameNum;
	this->frameTime = frameTime;
	currentFrame = 0;
	timer = 0;
	string path = "../Data/MainCharacter/";
	string fullpath;
	for (int i = 0; i < frameNum; i++)
	{
		Texture* texture = new Texture();
		if (i < 10) fullpath = path + name + "00" + to_string(i) + ".png";
		else fullpath = path + name + "0" + to_string(i) + ".png";
		texture->loadFromFile(fullpath);
		textures.push_back(texture);
		this->setOrigin(42, 42);
	}
}

void Animation::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= frameTime)
	{
		timer -= frameTime;
		currentFrame++;
		if (currentFrame == frameNum)
			currentFrame = 0;
	}
	this->setTexture(*textures[currentFrame]);
}

Texture* Animation::getTexture()
{
	return textures[currentFrame];
}