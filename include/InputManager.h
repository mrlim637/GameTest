#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class InputManager
{
    public:
        InputManager();
        ~InputManager();

        void update(sf::Event event);

        bool keyPressed(sf::Keyboard::Key key);
        bool keyPressed(std::vector<sf::Keyboard::Key> keys);

        bool keyReleased(int key);
        bool keyReleased(std::vector<int> keys);

        bool keyDown(sf::RenderWindow& window, int key);
        bool keyDown(sf::RenderWindow& window, std::vector<int> keys);

    protected:
    private:
        sf::Event event;
};

#endif // INPUTMANAGER_H
