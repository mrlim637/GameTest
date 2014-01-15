#include "Animation.h"

Animation::Animation()
{
    //ctor
}

Animation::~Animation()
{
    //dtor
}

void Animation::loadContent(std::string inText, sf::Image& image, sf::Vector2f pos)
{
    this->preText = inText;
    std::cout << "Loading text " << inText << std::endl;
    this->image = image;
    this->pos = pos;
    if(!font.loadFromFile("Font1.ttf"))
    {
        std::cout << "Font failed to load\n";
    }

    alpha = 1.0;
    textColor = sf::Color(114, 77, 255);

    if(image.getSize().x > 0)
        texture.loadFromImage(image);

    sprite.setTexture(texture);
    text.setString(preText);
    active = false;
}

void Animation::unloadConent()
{

}

void Animation::update(double deltaTime)
{

}

void Animation::draw(sf::RenderWindow& window)
{
    sprite.setColor(sf::Color(255, 255, 255, 255 * alpha));
    sprite.setPosition(pos);
    sprite.setScale(scale, scale);
    //sprite.setTextureRect()

    if(text.getString() != "")
    {
        std::string s = text.getString();
        //text.setString("Hello");
        text.setFont(font);
        text.setPosition(pos);
        text.setColor(sf::Color(255, 255, 255, 255 * alpha));
        //text.setScale(scale, scale);
        window.draw(text);
    }

    if(sprite.getTexture() != NULL)
        window.draw(sprite);
}

double &Animation::getAlpha()
{
    return alpha;
}

bool &Animation::getActive()
{
    return active;
}

double &Animation::getScale()
{

    return scale;
}

void Animation::setAlpha(double val)
{
    alpha = val;
}

sf::Vector2f& Animation::getPos()
{
    return pos;
}

sf::Text& Animation::getText()
{
    return this->text;
}
