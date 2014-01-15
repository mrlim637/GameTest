#include "FadeAnimation.h"
#include <iostream>

FadeAnimation::FadeAnimation()
{
    //ctor
}

FadeAnimation::~FadeAnimation()
{
    //dtor
}

void FadeAnimation::loadContent(std::string text, sf::Image& image, sf::Vector2f pos)
{
    Animation::loadContent(text, image, pos);
    increase = false;
    fadeSpeed = 1.0;
}

void FadeAnimation::unloadContent()
{

}

void FadeAnimation::update(double deltaTime)
{
    if(active)
    {
        if(!increase)
            alpha -= deltaTime * fadeSpeed;
        else
            alpha += deltaTime * fadeSpeed;

        if(alpha >= 1.0)
        {
            alpha = 1.0;
            increase = false;
        }
        else if(alpha <= 0.0)
        {
            alpha = 0.0;
            increase = true;
        }
    }
    else
    {
        alpha = 1.0;
    }

    Animation::update(deltaTime);

}

void FadeAnimation::draw(sf::RenderWindow& window)
{
    Animation::draw(window);
}

void FadeAnimation::setAlpha(double val)
{
    alpha = val;
    if(alpha == 0.0)
        increase = true;
    else
        increase = false;
}
