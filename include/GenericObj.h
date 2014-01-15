#ifndef GENERICOBJ_H
#define GENERICOBJ_H

#include <SFML/Graphics.hpp>
#include "InputManager.h"

class GenericObj
{
    public:
        GenericObj();
        ~GenericObj();
        virtual void loadContent();
        virtual void updateEvent(InputManager input);
        virtual void update(double deltaTime);
        void draw(sf::RenderWindow& window);

    protected:
         sf::Vector2f objSize;
         sf::RectangleShape shape;
         sf::Vector2f velocity;
    private:

};

#endif // GENERICOBJ_H
