#pragma once

#include "Animation.h"

class Zombie
{
protected:
    /* Animations */
    Animation** animations;

    /* Size and Positioning */
    sf::Rect<float> bounds;

    /* Stats */
    float move_distance;
    int health, attack;

    /* Status */
    uint32_t state;

    virtual void setState(uint32_t) = 0;

public:
    Zombie();
    Zombie(Animation** animations, sf::FloatRect position);

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update() = 0;

    virtual void walk() = 0;
    virtual void eat() = 0;
    virtual void die() = 0;
        
    const sf::Rect<float> getBounds();
};

