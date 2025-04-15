#pragma once

#include "Animation.h"

class Zombie
{
protected:
    /* Animations */
    Animation** animations;
    uint32_t number_of_animations;
    bool* active_animations;

    /* Size and Positioning */
    sf::Vector2f position;
    sf::Vector2i size;

    /* Stats */
    float distance_per_walk;
    int health, attack;

    /* Status */
    uint32_t current_state;

public:
    Zombie() = delete;
    Zombie(Animation** animations, uint32_t number_of_animations, uint32_t current_state,
        sf::Vector2f position, sf::Vector2i size, int health, int attack, float distance_per_walk);
    ~Zombie();

    virtual void walk() = 0;
    virtual void eat() = 0;
    virtual bool die() = 0;

    void setDistancePerWalk(uint32_t distance);
    sf::Vector2f getPosition();
    sf::Vector2i getSize();

    virtual void draw(sf::RenderWindow& window);
};

