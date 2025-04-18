#pragma once

#include "Zombie.h"

namespace NormalZombieConfig
{
    constexpr float move_distance = 0.4f;

}

class NormalZombie : public Zombie
{
private:
    enum State
    {
        WALK,
        EAT,
        WALK_DIE,
        EAT_DIE
    };

    void setState(uint32_t state) override;

public:
    NormalZombie() = delete;
    NormalZombie(Animation** animations                                                   , sf::FloatRect bounds);
    ~NormalZombie();

    void draw(sf::RenderWindow& window);
    void update() override;
    void walk() override;
    void eat() override;
    void die() override;
};

