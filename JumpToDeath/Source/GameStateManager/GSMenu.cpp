#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	m_Background.Init();

	GameButton* button;
	//Play Button
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2, screenHeight / 2 + screenHeight / 10);
	button->setSize(sf::Vector2f(150, 150));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("exit");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 5, screenHeight - screenHeight / 6);
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("setting");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 5, screenHeight - screenHeight / 6);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); });
	m_ListBtn.push_back(button);

	//About Button
	button = new GameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2, screenHeight - screenHeight / 6);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	m_ListBtn.push_back(button);

	//Title
	m_Title.setString("JUMP TO DEATH");
	m_Title.setCharacterSize(100);
	m_Title.setFont(*DATA->getFont("BUBBLE"));
	m_Title.setPosition(screenWidth / 2 - 410, screenHeight / 5);

	DATA->playMusic("senbon");
	DATA->getMusic("senbon")->setLoop(true);
	DATA->getMusic("senbon")->setVolume(30);
}

void GSMenu::Update(float deltaTime)
{
	m_Background.Update(deltaTime);

	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}