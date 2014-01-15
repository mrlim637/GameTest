#include "LevelScreen.h"

LevelScreen::LevelScreen()
{
    //ctor
}

LevelScreen::~LevelScreen()
{
    //dtor
}

void LevelScreen::loadContent()
{
    if(!font.loadFromFile("Font1.ttf"))
        std::cout << "Font failed to load\n";

    text.setString("First Level");
    text.setFont(font);

    character.loadContent();
}

void LevelScreen::unloadContent()
{

}

void LevelScreen::updateEvent(sf::Event event)
{
    input.update(event);
    character.updateEvent(input);
}

void LevelScreen::update(double deltaTime)
{
    character.update(deltaTime);
}

void LevelScreen::draw(sf::RenderWindow& window)
{
    window.draw(text);
    character.draw(window);
}
