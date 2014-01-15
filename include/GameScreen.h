#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "FileManager.h"

class GameScreen
{
    public:
        GameScreen();
        ~GameScreen();
        virtual void loadContent();
        virtual void unloadContent();
        virtual void updateEvent(sf::Event event);
        virtual void update(double deltaTime);
        virtual void draw(sf::RenderWindow& window);
    protected:
        InputManager input;
        std::vector<sf::Keyboard::Key> keys;

        FileManager file;
        std::vector<std::vector<std::string> > attr;
        std::vector<std::vector<std::string> > content;
    private:
};

#endif // GAMESCREEN_H
