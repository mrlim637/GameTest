#include "MainChar.h"

MainChar::MainChar()
{

}

void MainChar::loadContent()
{
    objSize.x = 25;
    objSize.y = 25;
    speed = 1000;
    jumpSpeed = 1000;
    groundHeight = 440;
    velocity.x = 0;
    velocity.y = 0;
    gravity = 1;

    shape.setPosition(500, 500);
    shape.setSize(objSize - sf::Vector2f(3, 3));
    shape.setOutlineThickness(3);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(sf::Color(100, 100, 200));
}

/*void MainChar::moveDown(double deltaTime)
{
    if(shape.getPosition().y + objSize.y / 2 < gameHeight - 5.0)
        shape.move(0.0, speed * deltaTime);
}

void MainChar::moveUp(double deltaTime)
{
    if(shape.getPosition().y - objSize.y / 2 > 5.0)
        shape.move(0.0, -speed * deltaTime);
}

void MainChar::moveLeft(double deltaTime)
{
    if(shape.getPosition().x + objSize.x / 2 > 30.0)
        shape.move(-speed * deltaTime, 0.0);
}

void MainChar::moveRight(double deltaTime)
{
    if(shape.getPosition().x + objSize.y / 2 < gameWidth - 5.0)
        shape.move(speed * deltaTime, 0.0);
}*/

bool MainChar::validMove()
{
    //Right
    if(shape.getPosition().x + objSize.y / 2 < gameWidth - 5.0)
        return true;
    //Left
    else if(shape.getPosition().x + objSize.x / 2 > 30.0)
        return true;
    //Up
    else if(shape.getPosition().y - objSize.y / 2 > 5.0)
        return true;
    //Down
    else if(shape.getPosition().y + objSize.y / 2 < gameHeight - 5.0)
        return true;
    else
        return false;

}


void MainChar::updateEvent(InputManager input)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x = speed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x = -speed;
    else
    {
        if(velocity.y == 0)
            velocity.x = 0;

        if(velocity.x > 0 && velocity.y != 0)
            velocity.x -= speed;
        else if(velocity.x < 0 && velocity.y != 0)
            velocity.x += speed;
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity.y = -jumpSpeed;
    else
        velocity.y = 0;

}

void MainChar::update(double deltaTime)
{

    if(shape.getPosition().y + shape.getSize().y < groundHeight || velocity.y < 0)
    {
        velocity.y += gravity;
    }
    else
    {
        shape.setPosition((shape.getPosition().x), groundHeight + shape.getSize().y);
        velocity.y = 0;
    }

    std::cout << velocity.x << " " << velocity .y << std::endl;
    if(validMove())
        shape.move(velocity.x * deltaTime, velocity.y * deltaTime);
    else
    {
        velocity.x = 0;
        velocity.y = 0;
    }
}

void MainChar::draw(sf::RenderWindow& window)
{
    GenericObj::draw(window);
}
