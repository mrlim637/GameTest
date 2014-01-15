#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{
    //ctor
}

InputManager::~InputManager()
{
    //dtor
}

void InputManager::update(sf::Event event)
{
    this->event = event;
}

bool InputManager::keyPressed(sf::Keyboard::Key key)
{
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Code(key))
        return true;
    if(event.type == sf::Event::KeyPressed && event.key.code == key)
        return true;*/

    if(sf::Keyboard::isKeyPressed(key))
        return true;

    return false;

    //return false;
}

bool InputManager::keyPressed(std::vector<sf::Keyboard::Key> keys)
{
    for(unsigned i = 0; i < keys.size(); ++i)
    {
        if(sf::Keyboard::isKeyPressed(keys[i]))
            return true;
    }

    return false;
}

bool InputManager::keyReleased(int key)
{
    if(event.key.code == key && sf::Event::KeyReleased)
        return true;

    return false;
}

bool InputManager::keyReleased(std::vector<int> keys)
{
    for(unsigned i = 0; i < keys.size(); ++i)
    {
        if(event.key.code == keys[i] && sf::Event::KeyReleased)
            return true;
    }

    return false;
}

/*bool InputManager::keyDown(sf::RenderWindow& window, int key)
{
    if(e;
        return true;

    return false;
}

bool InputManager::keyDown(sf::RenderWindow& window, std::vector<int> keys)
{
    for(int i = 0; i < keys.size(); ++i)
    {
         if(window.getInput().IsKeyDown(keys[i]));
        return true;
    }

    return false;

}*/
