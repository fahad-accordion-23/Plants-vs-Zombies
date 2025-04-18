#pragma once

#include <iostream>
#include "ZombieFactory.h"
#include "NormalZombie.h"

class NormalZombieFactory : public ZombieFactory
{
private:
    static NormalZombieFactory* instance;
    sf::Texture textures[6];
    Animation** states;

    NormalZombieFactory();

public:
    NormalZombieFactory(const NormalZombieFactory& obj) = delete;

    static NormalZombieFactory* getInstance();
    Zombie* createZombie(sf::Vector2f position) override;
};

