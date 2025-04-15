#pragma once

#include <iostream>
#include "Zombie.h"

class ZombieFactory 
{
protected:
    uint32_t number_of_animations;
    const char** paths;
    sf::Texture* textures;
    sf::Sprite** sprites;
    Animation** animations;

    virtual void initializeAssets();
    virtual void initializeAnimations() = 0;
public:
    ZombieFactory() = delete;
    ZombieFactory(uint32_t number_of_animations);
    ~ZombieFactory();

    virtual Zombie* createZombie(sf::Vector2f position) = 0;
};

