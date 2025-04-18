#include "NormalZombieFactory.h"

NormalZombieFactory* NormalZombieFactory::instance = nullptr;

NormalZombieFactory::NormalZombieFactory()
{
    textures[0].loadFromFile("./assets/zombie/normal/walk.png");
    textures[1].loadFromFile("./assets/zombie/normal/eat.png");
    textures[2].loadFromFile("./assets/zombie/normal/walk_lost_head.png");
    textures[3].loadFromFile("./assets/zombie/normal/eat_lost_head.png");
    textures[4].loadFromFile("./assets/zombie/normal/die_lost_head.png");
    textures[5].loadFromFile("./assets/zombie/normal/head_fall.png");

    /* WALK STATE */
    Animation walk(textures[0], 22, 1, 22, 5, 0, 0, true);
    walk.setPosition({ 0, 0 });

    /* EAT STATE */
    Animation eat(textures[1], 21, 1, 21, 5, 0, 0, true);
    eat.setPosition({ 0, 0 });

    /* WALK DIE + EAT DIE STATES */
    Animation head_pop(textures[5], 12, 1, 12, 10, 0, 60, false);
    head_pop.setPosition({ 60, 0 });

    /* WALK DIE STATE */
    Animation walk_no_head(textures[2], 18, 1, 9, 9, 0, 0, false);
    Animation walk_no_head_fall(textures[4], 10, 1, 10, 9, 9 * 9, 60, false);
    walk_no_head.setPosition({ 0, 0 });
    walk_no_head_fall.setPosition({ -1 * (10 + 9 * 9), 0});

    /* EAT DIE STATE */
    Animation eat_no_head(textures[3], 11, 1, 11, 5, 0, 0, false);
    Animation eat_no_head_fall(textures[4], 10, 1, 10, 5, 11 * 5, 60, false);
    eat_no_head.setPosition({ 0, 0 });
    eat_no_head_fall.setPosition({ 0, 0 });

    /* Initializing States */
    states = new Animation * [4];
    states[0] = new Animation[1]{ walk };
    states[1] = new Animation[1]{ eat };
    states[2] = new Animation[3]{ head_pop, walk_no_head, walk_no_head_fall };
    states[3] = new Animation[3]{ head_pop, eat_no_head, eat_no_head_fall };
}

NormalZombieFactory* NormalZombieFactory::getInstance()
{
    if (instance == nullptr)
        instance = new NormalZombieFactory();

    return instance;
}

Zombie* NormalZombieFactory::createZombie(sf::Vector2f position)
{
    Animation** animations = new Animation * [4];
    animations[0] = new Animation[1]{ states[0][0] };
    animations[1] = new Animation[1]{ states[1][0] };
    animations[2] = new Animation[3]{ states[2][0], states[2][1], states[2][2] };
    animations[3] = new Animation[3]{ states[3][0], states[3][1], states[3][2] };

    sf::FloatRect bounds;
    bounds.position = position;
    bounds.size = { 80, 144 };
    return new NormalZombie(animations, bounds);
}
