#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "FadeAnimation.h"
#include "FileManager.h"
#include "InputManager.h"
//#include "LevelScreen.h"
//#include "ScreenManager.h"
#include <iostream>

class TitleScreen;

class MenuManager
{
    public:
        MenuManager();
        ~MenuManager();

        void loadContent(std::string menuId);
        void unloadContent();
        void updateEvent(InputManager input);
        void update(double deltaTime);
        void draw(sf::RenderWindow& window);
        int getItem();

    protected:
    private:
        std::vector<std::vector<std::string> > attr;
        std::vector<std::vector<std::string> > content;

        FileManager file;

        std::vector<std::vector<Animation*> > anim;
        std::vector<Animation*> tempAnim;

        sf::Image image;
        sf::Image null;

        std::vector<sf::Image> menuImages;
        std::vector<std::string> menuItems;

        sf::Vector2f pos;
        int axis;
        std::string align;
        std::vector<std::string> animType;

        int itemNum;

        void equalizeMenu();
        void setAnim();
        void setPos();
};

#endif // MENUMANAGER_H
