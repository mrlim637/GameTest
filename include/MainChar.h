#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <iostream>
#include "GenericObj.h"
//#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class MainChar : public GenericObj
{
    private:
         double speed;
         double jumpSpeed;
         double gravity;
         double groundHeight;
         int gameWidth;
         int gameHeight;
        bool validMove();

    public:
        MainChar();
        void loadContent();
        void updateEvent(InputManager input);
        void update(double deltaTime);

        void draw(sf::RenderWindow& window);
};

#endif // MAINCHAR_H
