#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Animation
{
    public:
        Animation();
        ~Animation();

        virtual void loadContent(std::string text, sf::Image& image, sf::Vector2f pos);
        virtual void unloadConent();
        virtual void update(double deltaTime);
        virtual void draw(sf::RenderWindow& window);

        virtual void setAlpha(double val);

        double &getAlpha();
        bool &getActive();
        double &getScale();
        sf::Vector2f& getPos();
        sf::Text& getText();

        template<typename T>
        void setValue(T& variable, T value)
        {
            variable = value;
        }

    protected:
        double alpha;
        std::string preText;
        sf::Font font;
        sf::Text text;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f pos;
        sf::Color textColor;
        sf::IntRect sourceRect;
        bool active;

        double scale;

    private:
};

#endif // ANIMATION_H
