#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
    //ctor
}

TitleScreen::~TitleScreen()
{
    //dtor
}

void TitleScreen::loadContent()
{
    if(!font.loadFromFile("Font1.ttf"))
        std::cout << "Font failed to load\n";

    //text.setString("Title Screen");
    //text.setFont(font);

    keys.push_back(sf::Keyboard::Z);
    keys.push_back(sf::Keyboard::Return);

    menu.loadContent("Title");
}


void TitleScreen::unloadContent()
{
    GameScreen::unloadContent();
    menu.unloadContent();
}


void TitleScreen::updateEvent(sf::Event event)
{
    if(input.keyPressed(keys) && menu.getItem() == 0)
        ScreenManager::getInstance().addScreen(new LevelScreen);

    input.update(event);
    menu.updateEvent(input);
}

void TitleScreen::update(double deltaTime)
{
    menu.update(deltaTime);
}

void TitleScreen::draw(sf::RenderWindow& window)
{
    window.draw(text);
    menu.draw(window);
}
