#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "WindowConfig.h"
#include "NormalZombieFactory.h"

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
    sf::Texture background_texture;
    background_texture.loadFromFile("./assets/background/day.jpg");
    sf::Sprite background_sprite(background_texture);

    /* Zombie Animation Setup */
    NormalZombieFactory normal_zombie_factory;
    Zombie* my_zombie = normal_zombie_factory.createZombie({ 300, 300 });

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

        /* Processing */
        if (counter < 200)
            my_zombie->walk();
        else if (counter < 400)
            my_zombie->die();
        else if (counter < 600)
            my_zombie->walk();
        else if (counter < 800)
            my_zombie->eat();
        else
            my_zombie->die();

        /* Drawing */
        window.draw(background_sprite);
        my_zombie->draw(window);

        /* Displaying */
        window.display();
    }

    return 0;
}