#include "MenuManager.h"

MenuManager::MenuManager()
{
    //ctor
}

MenuManager::~MenuManager()
{
    //dtor
}

void MenuManager::equalizeMenu()
{
    for(unsigned i = 0; i < menuItems.size(); ++i)
    {
        if(menuImages.size() == i)
        {
             menuImages.push_back(image);
        }
    }

    for(unsigned i = 0; i < menuImages.size(); ++i)
    {
        if(menuItems.size() == i)
        {
            menuItems.push_back("");
        }
    }
}

void MenuManager::setAnim()
{
    for(unsigned i = 0; i < menuItems.size(); ++i)
    {
        for(unsigned j = 0; j < animType.size(); ++j)
        {
            if(animType[j] == "fade")
            {
                tempAnim.push_back(new FadeAnimation);
                tempAnim[tempAnim.size() - 1]->loadContent(menuItems[i],
                                                          menuImages[i],
                                                          pos);
            }
        }

        anim.push_back(tempAnim);
        tempAnim.clear();
    }
}

void MenuManager::setPos()
{
    sf::Vector2f pos = this->pos;

    for(unsigned i = 0; i < anim.size(); ++i)
    {
        for(unsigned j = 0; j < anim[i].size(); ++j)
        {
            anim[i][j]->setValue(anim[i][j]->getPos(), pos);
        }

        double width = menuImages[i].getSize().y + anim[i][0]->getText().getLocalBounds().width;
        double height = menuImages[i].getSize().x + anim[i][0]->getText().getLocalBounds().height;

        if(axis == 1)
            pos.x += 25 + width;
        else
            pos.y += 25 + height;
    }
}

void MenuManager::loadContent(std::string menuID)
{
    null.loadFromFile("null.jpg");

    file.loadContent("load/menu.txt", attr, content, menuID);

    itemNum = 0;

    for(unsigned i = 0; i < attr.size(); ++i)
    {
        for(unsigned j = 0; j < attr[i].size(); ++j)
        {
            std::string att = attr[i][j];
            std::string con = content[i][j];

            if(att == "item")
            {
                menuItems.push_back(con);
            }
            else if(att == "image")
            {
                image.loadFromFile(con);
                menuImages.push_back(image);
            }
            else if(att == "position")
            {
                std::string position[2];
                position[0] = con.substr(0, con.find(','));
                position[1] = con.substr(con.find(',') + 1);

                this->pos.x = atof(position[0].c_str());
                this->pos.y = atof(position[1].c_str());

            }
            else if(att == "align")
            {
                align = con;
            }
            else if(att == "axis")
            {
                axis = atoi(con.c_str());
            }
            else if(att == "animation")
            {
                animType.push_back(con);
            }
        }
    }

    equalizeMenu();
    setAnim();
    setPos();

}
void MenuManager::unloadContent()
{
    menuItems.clear();
    menuImages.clear();

    for(unsigned i = 0; i < anim.size(); ++i)
    {
        for(unsigned j = 0; j < anim[i].size(); ++j)
        {
            delete anim[i][j];
        }
    }

    anim.clear();
    animType.clear();
    attr.clear();
    content.clear();
}

void MenuManager::updateEvent(InputManager input)
{
    if(axis == 1)
    {
        if(input.keyPressed((sf::Keyboard::Right)) || input.keyPressed(sf::Keyboard::D))
            itemNum++;
        else if(input.keyPressed(sf::Keyboard::Left) || input.keyPressed(sf::Keyboard::A))
            itemNum--;
    }
    else
    {
        if(input.keyPressed((sf::Keyboard::Down)) || input.keyPressed(sf::Keyboard::S))
            itemNum++;
        else if(input.keyPressed(sf::Keyboard::Up) || input.keyPressed(sf::Keyboard::W))
            itemNum--;
    }

    std::cout << itemNum << std::endl;
}

void MenuManager::update(double deltaTime)
{
    if(itemNum < 0)
        itemNum = menuItems.size() - 1;
    else if(itemNum > menuItems.size() - 1)
        itemNum = 0;

    for(unsigned i = 0; i < anim.size(); ++i)
    {
        for(unsigned j = 0; j < anim[i].size(); ++j)
        {
            anim[i][j]->setValue(anim[i][j]->getActive(), false);
            if(i == itemNum)
                anim[i][j]->setValue(anim[i][j]->getActive(), true);

            anim[i][j]->update(deltaTime);
        }
    }
}

void MenuManager::draw(sf::RenderWindow& window)
{
    for(unsigned i = 0; i < anim.size(); ++i)
    {
        for(unsigned j = 0; j < anim[i].size(); ++j)
        {
            anim[i][j]->draw(window);
        }
    }
}

int MenuManager::getItem()
{
    return itemNum;
}
