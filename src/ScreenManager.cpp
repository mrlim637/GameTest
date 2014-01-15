#include "ScreenManager.h"

GameScreen *currentScreen, *newScreen;

ScreenManager::ScreenManager()
{
    //ctor
}

ScreenManager::~ScreenManager()
{
    //dtor
}

double ScreenManager::getAlpha()
{
    return fade.getAlpha();
}

void ScreenManager::transition(double deltaTime)
{
    if(transitiond)
    {
        fade.update(deltaTime);
        if(fade.getAlpha() >= 1.0)
        {
            currentScreen->unloadContent();
            delete currentScreen;
            currentScreen = newScreen;
            currentScreen->loadContent();
            newScreen = NULL;
        }
        else if(fade.getAlpha() <= 0.0)
        {
            transitiond = false;
            fade.setValue(fade.getActive(), false);
        }
    }
}

ScreenManager& ScreenManager::getInstance()
{
    static ScreenManager instance;
    return instance;
}

void ScreenManager::addScreen(GameScreen* screen)
{
    transitiond = true;
    newScreen = screen;
    fade.setValue(fade.getActive(), true);
    fade.setAlpha(0.0);
}

void ScreenManager::initialize()
{
    currentScreen = new SplashScreen();
    transitiond = false;
    //file.loadContent("load/splash.txt", attributes, contents);
}

void ScreenManager::loadContent()
{
    currentScreen->loadContent();

    sf::Image image;
    sf::Vector2f pos;

    fade.loadContent("", image, pos);
    fade.setAlpha(0.0);
}

void ScreenManager::unloadContent()
{

}

void ScreenManager::updateEvent(sf::Event event)
{
    currentScreen->updateEvent(event);
}

void ScreenManager::update(double deltaTime)
{
    if(!transitiond)
        currentScreen->update(deltaTime);
    transition(deltaTime);
}

void ScreenManager::draw(sf::RenderWindow& window)
{
    currentScreen->draw(window);
}
