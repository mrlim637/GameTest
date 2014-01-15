#include "GenericObj.h"

#define GameWidth 800
#define GameHeight 600

GenericObj::GenericObj()
{
    //ctor
}

GenericObj::~GenericObj()
{
    //dtor
}

void GenericObj::loadContent()
{

}

void GenericObj::updateEvent(InputManager input)
{

}

void GenericObj::update(double deltaTime)
{

}

void GenericObj::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
