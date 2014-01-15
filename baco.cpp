
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "char.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Define some constants
    const double pi = 3.14159f;
    const int gameWidth = 800;
    const int gameHeight = 600;

    MainChar tumlum(25, 25, 400, gameWidth, gameHeight);

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Adventures of Tum Lum");
    window.setVerticalSyncEnabled(true);

    // Load the sounds used in the game
    /*sf::SoundBuffer ballSoundBuffer;
    if (!ballSoundBuffer.loadFromFile("resources/ball.wav"))
        return EXIT_FAILURE;
    sf::Sound ballSound(ballSoundBuffer);*/

    // Load the text font
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(50.f, 150.f);
    pauseMessage.setColor(sf::Color::White);
    pauseMessage.setString("Welcome to the Adventures of\n Tum Lum Slum Jum");

    sf::Text timercount;
    timercount.setFont(font);
    timercount.setCharacterSize(40);
    timercount.setPosition(50.f, 150.f);
    timercount.setColor(sf::Color::White);

    // Define the paddles properties
    sf::Clock AITimer;
    const sf::Time AITime   = sf::seconds(0.1f);
    const double paddleSpeed = 400.0;

    sf::Clock clock;
    bool isPlaying = false;
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            // Space key pressed: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                if (!isPlaying)
                {
                    // (re)start the game
                    isPlaying = true;
                    clock.restart();

                    // Reset the position of the paddles and ball
                    tumlum.setPos(10.0 + tumlum.getSize().x / 2, gameHeight - 15.0);

                }
            }
        }

        if (isPlaying)
        {
            double deltaTime = clock.restart().asSeconds();

            // Move the character
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                tumlum.moveUp(deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                tumlum.moveDown(deltaTime);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                tumlum.moveLeft(deltaTime);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                tumlum.moveRight(deltaTime);
            }
        }

        // Clear the window
        window.clear(sf::Color(50, 200, 50));

        if (isPlaying)
        {
            // Draw the paddles and the ball
            window.draw(tumlum.getShape());
        }
        else
        {
            // Draw the pause message
            window.draw(pauseMessage);
        }

        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
