#include "Block.h"

Block::Block()
{

}

Block::Block(std::string link, sf::Vector2f size, sf::Vector2f position) {
	m_HitBox.setTexture(DATA->getTexture(link));
	m_HitBox.setOrigin(size / 2.f);
	m_HitBox.setSize(size);
	m_HitBox.setPosition(position);
	/*m_HitBox.setOutlineThickness(1.f);
	m_HitBox.setOutlineColor(sf::Color::Red);*/
}

Block::~Block() {
}

void Block::Render(sf::RenderWindow* window) {
	window->draw(m_HitBox);
}