#pragma once

#include <iostream>
#include "Zombie.h"
#include "Animation.h"

class ZombieFactory 
{
protected:
    
public:
    ZombieFactory() = default;

    virtual Zombie* createZombie(sf::Vector2f position) = 0;
};

