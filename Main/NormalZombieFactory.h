#pragma once

#include <iostream>
#include "ZombieFactory.h"
#include "NormalZombie.h"

class NormalZombieFactory : public ZombieFactory
{
protected:
    void initializeAssets() override;
    void initializeAnimations() override;

public:
    NormalZombieFactory();
    ~NormalZombieFactory();
    Zombie* createZombie(sf::Vector2f position) override;
};

