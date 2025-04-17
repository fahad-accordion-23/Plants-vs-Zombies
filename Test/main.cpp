#include <iostream>
#include <SFML/Graphics.hpp>

#include "./../Main/Animation.cpp"
#include "./../Main/AnimationController.cpp"

#include "./../Main/WindowConfig.h"
#include "./../Main/NormalZombieConfig.h"

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
    sf::Texture zombie_walk;
    zombie_walk.loadFromFile(NormalZombieConfig::P_WALK);
    Animation my_anim(zombie_walk, 1, 22, 5, 10, 10, true);
    my_anim.setPosition({ 1000, 300 });
    my_anim.setTextureRect(sf::Rect<int>({ 0, 0 }, { 166, 144 }));

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
        my_anim.update();
        if (counter < 200)
        {
            my_anim.move({ -1, 0 });
            my_anim.play();
        }
        else if (counter < 400)
        {
            my_anim.pause();
        }
        else if (counter < 600)
        {
            my_anim.move({ -1, 0 });
            my_anim.play();
        }
        else if (counter == 600)
        {
            my_anim.reset();
        }

        /* Drawing */
        window.draw(background_sprite);
        window.draw(my_anim);

        /* Displaying */
        window.display();
    }

    return 0;
}