#pragma once

#include "Zombie.h"
#include "NormalZombieConfig.h"
using namespace NormalZombieConfig;

class NormalZombie : public Zombie
{
private:
    Animation* animations[TOTAL_ANIMATIONS];

public:

    NormalZombie() = delete;
    NormalZombie(Animation* anims[TOTAL_ANIMATIONS], sf::Vector2f position);

    void walk() override;
    void eat() override;
    bool die() override;

    /*
    void setDistancePerWalk(uint32_t distance);
    sf::Vector2f getPosition();
    sf::Vector2i getSize();
    */

    void draw(sf::RenderWindow& window) override;
};

