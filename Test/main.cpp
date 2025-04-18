#include <iostream>
#include <SFML/Graphics.hpp>

#include "./../Main/AnimationController.cpp"
#include "./../Main/Animation.cpp"
#include "./../Main/ZombieFactory.cpp"
#include "./../Main/NormalZombieFactory.cpp"
#include "./../Main/Zombie.cpp"
#include "./../Main/NormalZombie.cpp"
#include "./../Main/WindowConfig.h"

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

    /* Animation */
    NormalZombieFactory* factory = NormalZombieFactory::getInstance();
    Zombie* my_zombie = factory->createZombie({ 600, 300 });
    Zombie* my_zombie_2 = factory->createZombie({ 700, 100 });

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
        {
            my_zombie->walk();
            my_zombie_2->walk();
        }
        else if (counter < 400)
        {
            my_zombie->eat();
            my_zombie_2->walk();
        }
        else if (counter < 600)
        {
            my_zombie_2->die();
            my_zombie->die();
        }

        my_zombie_2->update();
        my_zombie->update();

        /* Drawing */
        window.draw(background_sprite);
        my_zombie->draw(window);
        my_zombie_2->draw(window);

        /* Displaying */
        window.display();
    }

    return 0;
}