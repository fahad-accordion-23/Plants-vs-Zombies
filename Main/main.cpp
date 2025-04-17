#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"

#include "WindowConfig.h"
#include "NormalZombieConfig.h"

int main()
{
    /* Window Init */
    sf::RenderWindow window;
    window.create(sf::VideoMode({ window::WIDTH, window::HEIGHT }), "Plants vs Zombies");
    window.setFramerateLimit(window::FPS);

    sf::Image icon;
    if (!icon.loadFromFile(window::ICON))
        std::cerr << "Unable to load asset " << window::ICON << std::endl;
    else
        window.setIcon(icon.getSize(), icon.getPixelsPtr());

    /* Background */
    sf::Texture background_texture;
    background_texture.loadFromFile("./assets/background/day.jpg");
    sf::Sprite background_sprite(background_texture);

    /* Game Loop */
    uint64_t counter = 0;
    while (window.isOpen())
    {
        counter += 1;

        /* Event Handling */
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        /* Drawing */
        window.draw(background_sprite);
        window.draw(my_anim);

        /* Displaying */
        window.display();
    }

    return 0;
}