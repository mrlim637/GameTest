#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight, 32),
                            "Test Window");

    //sf::Vector2f size(255, 255);
    sf::RectangleShape fade(sf::Vector2f(ScreenWidth, ScreenHeight));
    fade.setFillColor(sf::Color(0, 0, 0, 255));

    ScreenManager::getInstance().initialize();
    ScreenManager::getInstance().loadContent();

    sf::Clock clock;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            ScreenManager::getInstance().updateEvent(event);
        }
        double deltaTime = clock.restart().asSeconds();
        window.clear();
        ScreenManager::getInstance().update(deltaTime);
        fade.setFillColor(sf::Color(0, 0, 0, 255 * ScreenManager::getInstance().getAlpha()));
        ScreenManager::getInstance().draw(window);
        window.draw(fade);

        window.display();
    }

    return 0;
}
