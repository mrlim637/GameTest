#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

#include <SFML/Graphics.hpp>

class MainChar
{
    private:
         sf::Vector2f charSize;
         sf::RectangleShape character;
         double speed;
         int gameWidth;
         int gameHeight;

    public:
        MainChar(double x, double y, double speed, int width, int height);
        void moveLeft(double deltaTime);
        void moveRight(double deltaTime);
        void moveUp(double deltaTime);
        void moveDown(double deltaTime);
        void setPos(double x, double y);
        const sf::Vector2f& getPos();
        const sf::Vector2f& getSize();
        const sf::RectangleShape& getShape();
};

#endif // CHAR_H_INCLUDED
