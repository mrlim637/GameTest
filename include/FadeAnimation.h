#ifndef FADEANIMATION_H
#define FADEANIMATION_H

#include "Animation.h"

class FadeAnimation : public Animation
{
    public:
        FadeAnimation();
        ~FadeAnimation();

        void loadContent(std::string text, sf::Image& image, sf::Vector2f pos);
        void unloadContent();
        void update(double deltaTime);
        void draw(sf::RenderWindow& window);
        void setAlpha(double val);

    protected:
    private:
        bool increase;
        double fadeSpeed;
};

#endif // FADEANIMATION_H
