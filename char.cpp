#include "char.h"

MainChar::MainChar(double x, double y, double speed, int width, int height)
:charSize(x, y), speed(speed), gameWidth(width), gameHeight(height)
{
    character.setSize(charSize - sf::Vector2f(3, 3));
    character.setOutlineThickness(3);
    character.setOutlineColor(sf::Color::Black);
    character.setFillColor(sf::Color(100, 100, 200));
}

void MainChar::moveDown(double deltaTime)
{
    if(this->getPos().y + charSize.y / 2 < gameHeight - 5.0)
        character.move(0.0, speed * deltaTime);
}

void MainChar::moveUp(double deltaTime)
{
    if(this->getPos().y - charSize.y / 2 > 5.0)
        character.move(0.0, -speed * deltaTime);
}

void MainChar::moveLeft(double deltaTime)
{
    if(this->getPos().x + charSize.x / 2 > 30.0)
        character.move(-speed * deltaTime, 0.0);
}

void MainChar::moveRight(double deltaTime)
{
    if(this->getPos().x + charSize.y / 2 < gameWidth - 5.0)
        character.move(speed * deltaTime, 0.0);
}

void MainChar::setPos(double x, double y)
{
    character.setPosition(x, y);
}

const sf::Vector2f& MainChar::getPos()
{
    return character.getPosition();
}

const sf::Vector2f& MainChar::getSize()
{
    return charSize;
}

const sf::RectangleShape& MainChar::getShape()
{
    return character;
}
