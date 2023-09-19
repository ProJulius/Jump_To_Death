#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	m_Background.Init();

	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->PopState();
		});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		});
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("END GAME!");
	m_Title.setFont(*DATA->getFont("BUBBLE"));
	m_Title.setPosition(screenWidth / 2, screenHeight / 5);

}

void GSEnd::Update(float deltaTime)
{
	m_Background.Update(deltaTime);

	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}