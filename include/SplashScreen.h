#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"

class SplashScreen : public GameScreen
{
    public:
        SplashScreen();
        ~SplashScreen();

        void loadContent();
        void unloadContent();
        void updateEvent(sf::Event event);
        void update(double deltaTime);
        void draw(sf::RenderWindow& window);

    protected:
    private:
        sf::Text text;
        sf::Font font;
        sf::Image image;
        std::vector<FadeAnimation*> fade;
        int imgNum;
};

#endif // SPLASHSCREEN_H
