#ifndef LEVELSCREEN_H
#define LEVELSCREEN_H

#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "GameScreen.h"
#include "MainChar.h"

class LevelScreen : public GameScreen
{
    public:
        LevelScreen();
        ~LevelScreen();

        void loadContent();
        void unloadContent();
        void updateEvent(sf::Event event);
        void update(double deltaTime);
        void draw(sf::RenderWindow& window);

    protected:
    private:
        sf::Text text;
        sf::Font font;
        MainChar character;
};

#endif // LEVELSCREEN_H
