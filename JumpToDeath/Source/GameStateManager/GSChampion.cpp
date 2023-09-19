#include "GSChampion.h"

GSChampion::GSChampion()
{
}

GSChampion::~GSChampion()
{

}

void GSChampion::Exit()
{
}

void GSChampion::Pause()
{
}

void GSChampion::Resume()
{
}

void GSChampion::Init()
{
	m_Background.Init();

	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("return");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::MENU); });
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("CHAMPION");
	m_Title.setCharacterSize(75);
	m_Title.setFont(*DATA->getFont("BUBBLE"));
	m_Title.setPosition(screenWidth / 2 - 165, screenHeight / 5);

	//Tile Victory
	m_Instruction.setString("-Congratulations on winning !!! \n-You can have victory but you will never \n have crush.");
	m_Instruction.setCharacterSize(50);
	m_Instruction.setFont(*DATA->getFont("BUBBLE"));
	m_Instruction.setPosition(screenWidth / 2 - 650, screenHeight * 0.6);
	
}

void GSChampion::Update(float deltaTime)
{
	view.setCenter(screenWidth+104, screenHeight);
	m_Background.Update(deltaTime);

	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSChampion::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	window->draw(m_Title);
	window->draw(m_Instruction);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}