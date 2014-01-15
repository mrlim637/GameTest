#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::loadContent()
{
    imgNum = 0;

    if(!font.loadFromFile("Font1.ttf"))
        std::cout << "Font failed to load\n";

    text.setString("Splash Screen");
    text.setFont(font);

    keys.push_back(sf::Keyboard::Z);
    keys.push_back(sf::Keyboard::Return);

    file.loadContent("load/splash.txt", attr, content);
    for(unsigned i = 0; i < attr.size(); ++i)
    {
        for(unsigned j = 0; j < attr[i].size(); ++j)
        {
            std::string att = attr[i][j];

            if(att == "image")
            {
                sf::Vector2f pos(0, 0);
                image.loadFromFile(content[i][j]);
//                std::cout << "Content " << content[i][j] << std::endl;
                fade.push_back(new FadeAnimation);
                fade[fade.size() - 1]->loadContent("", image, pos);
                fade[fade.size() - 1]->setValue(fade[fade.size() - 1]->getActive(), true);
                fade[fade.size() - 1]->setValue(fade[fade.size() - 1]->getScale(), 1.0);
            }
        }
    }
}

void SplashScreen::unloadContent()
{
    GameScreen::unloadContent();
    for(unsigned i = 0; i < fade.size(); ++i)
    {
        fade[i]->unloadContent();
        delete fade[i];
    }

    fade.clear();
}

void SplashScreen::updateEvent(sf::Event event)
{
    input.update(event);
}

void SplashScreen::update(double deltaTime)
{
    if(fade[imgNum]->getAlpha() <= 0.0)
        imgNum++;

    if(imgNum != fade.size() - 1)
        fade[imgNum]->update(deltaTime);

    if(input.keyPressed(keys) || imgNum >= fade.size() - 1)
        ScreenManager::getInstance().addScreen(new TitleScreen);
}

void SplashScreen::draw(sf::RenderWindow& window)
{
    //window.draw(text);
    fade[imgNum]->draw(window);
}
