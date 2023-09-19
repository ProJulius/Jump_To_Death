#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	m_Background.Init();

	GameButton* button;
	//Close Button
	button = new GameButton();
	button->Init("return");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("ABOUT");
	m_Title.setCharacterSize(75);
	m_Title.setFont(*DATA->getFont("BUBBLE"));
	m_Title.setPosition(screenWidth / 2 - 150, screenHeight / 5);

	//Tile Game
	m_Instruction.setString("-Use the A, D keys to move the character. \n-Hold SPACE to set force and press A or D\n keys to choose jump direction. \n-Let's jump to the top to save your crush. \n Good Luck !!!");
	m_Instruction.setCharacterSize(50);
	m_Instruction.setFont(*DATA->getFont("BUBBLE"));
	m_Instruction.setPosition(screenWidth / 2 - 650, screenHeight * 0.6);
}

void GSAbout::Update(float deltaTime)
{
	m_Background.Update(deltaTime);

	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	window->draw(m_Title);
	window->draw(m_Instruction);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}