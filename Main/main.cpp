#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "WindowConfig.h"

int main()
{
    /* Window Init */
    sf::Window window(sf::VideoMode({ window::WIDTH, window::HEIGHT }), "Plants vs Zombies");
    window.setFramerateLimit(window::FPS);

    sf::Image icon;
    if (!icon.loadFromFile(window::ICON))
        std::cerr << "Unable to load asset " << window::ICON << std::endl;
    else
        window.setIcon(icon.getSize(), icon.getPixelsPtr());

    /* Game Loop */
    while (window.isOpen())
    {
        /* Event Handling*/
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }

    return 0;
}