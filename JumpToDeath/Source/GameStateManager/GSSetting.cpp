#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
{
	m_Background.Init();

	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("return");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//turn on music
	button = new GameButton();
	button->Init("music_on");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->getMusic("senbon")->setVolume(30); });
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("music_off");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->getMusic("senbon")->setVolume(0); });
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("SETTINGS");
	m_Title.setCharacterSize(75);
	m_Title.setFont(*DATA->getFont("BUBBLE"));
	m_Title.setPosition(screenWidth / 2 - 165, screenHeight / 5);

}

void GSSetting::Update(float deltaTime)
{
	m_Background.Update(deltaTime);

	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}