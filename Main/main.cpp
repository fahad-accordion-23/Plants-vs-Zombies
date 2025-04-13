#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "WindowConfig.h"
#include "Animation.h"

int main()                                                                                         
{
    /* Window Init */
    sf::RenderWindow window;
    window.create(sf::VideoMode({ window::WIDTH, window::HEIGHT }), "Plants vs Zombies");
    window.setFramerateLimit(window::FPS);

    /* Load Missing Texture */
    sf::Texture missing_texture;
    if (!missing_texture.loadFromFile("./assets/missing.png"))
    {
        std::cerr << "Unable to load asset " << "./assets/missing.png" << std::endl;
        return 0;
    }

    sf::Image icon;
    if (!icon.loadFromFile(window::ICON))
        std::cerr << "Unable to load asset " << window::ICON << std::endl;
    else
        window.setIcon(icon.getSize(), icon.getPixelsPtr());

    /* Background */
    sf::RectangleShape background({ window::WIDTH, window::HEIGHT });
    background.setFillColor(sf::Color(255, 255, 255, 255));

    /* Zombie Animation Setup */
    sf::Texture zombie_walk_texture;
    if (!zombie_walk_texture.loadFromFile("./assets/zombie/normal/walk.png"))
    {
        std::cerr << "Unable to load asset " << "./assets/zombie/normal/walk.png" << std::endl;
        zombie_walk_texture = missing_texture;
        zombie_walk_texture.setRepeated(true);
    }
    
    sf::Sprite zombie_walk_sprite(zombie_walk_texture);
    Animation zombie_walk_animation(window, zombie_walk_sprite, 22, 5, true);

    /* Game Loop */
    while (window.isOpen())
    {
        /* Event Handling */
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        /* Drawing */
        window.draw(background);
        zombie_walk_animation.draw({ 300, 300 });

        /* Displaying */
        window.display();
    }

    return 0;
}