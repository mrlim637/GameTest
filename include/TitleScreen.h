#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "ScreenManager.h"
#include "MenuManager.h"

class TitleScreen : public GameScreen
{
    public:
        TitleScreen();
        ~TitleScreen();

        void loadContent();
        void unloadContent();
        void updateEvent(sf::Event event);
        void update(double deltaTime);
        void draw(sf::RenderWindow& window);

    protected:
    private:
        sf::Text text;
        sf::Font font;

        MenuManager menu;
};

#endif // TITLESCREEN_H
