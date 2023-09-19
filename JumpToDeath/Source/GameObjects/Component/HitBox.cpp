#include "HitBox.h"

HitBox::HitBox()
{
}

HitBox::HitBox(sf::Vector2i size) :RectangleShape((sf::Vector2f)size)
{
	this->setOrigin(19,25);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	//this->setOutlineThickness(1.f);
	//this->setOutlineColor(sf::Color::Red);
	m_Velocity = sf::Vector2f(0, 0);
}

HitBox::~HitBox()
{

}

void HitBox::Init(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}

sf::Vector2f HitBox::getVelocity()
{
	return m_Velocity;
}
