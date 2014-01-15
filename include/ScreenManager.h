#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "ScreenManager.h"
#include "FadeAnimation.h"
#include "FileManager.h"
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "LevelScreen.h"

#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
    public:
        ~ScreenManager();
        static ScreenManager& getInstance();
        void initialize();
        void loadContent();
        void unloadContent();
        void updateEvent(sf::Event event);
        void update(double deltaTime);
        void draw(sf::RenderWindow& window);

        void addScreen(GameScreen* screen);

        double getAlpha();

    protected:
    private:
        //GameScreen *currentScreen, *newScreen;
        ScreenManager();
        ScreenManager(ScreenManager const&);
        void operator=(ScreenManager const&);
        void transition(double deltaTime);
        bool transitiond;
        FadeAnimation fade;

        GameScreen* newScreen;
        FileManager file;

        std::vector<std::vector<std::string> > attributes;
        std::vector<std::vector<std::string> > contents;
};

#endif // SCREENMANAGER_H
