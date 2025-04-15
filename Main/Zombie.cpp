#include "Zombie.h"

Zombie::Zombie(Animation ** animations, uint32_t number_of_animations, uint32_t current_state,
    sf::Vector2f position, sf::Vector2i size, int health, int attack, float distance_per_walk)
    : animations(animations), number_of_animations(number_of_animations), current_state(current_state),
    position(position), size(size), health(health), attack(attack), distance_per_walk(distance_per_walk)
{
    active_animations = new bool[number_of_animations];
    for (uint32_t i = 0; i < number_of_animations; i += 1)
        active_animations[i] = false;
}

Zombie::~Zombie()
{
    delete[] active_animations;
}

void Zombie::setDistancePerWalk(uint32_t distance)
{
    distance_per_walk = distance;
}

sf::Vector2f Zombie::getPosition()
{
    return position;
}

sf::Vector2i Zombie::getSize()
{
    return size;
}

void Zombie::draw(sf::RenderWindow& window)
{
    for (uint32_t i = 0; i < number_of_animations; i += 1)
    {
        if (active_animations[i])
            animations[i]->draw(window, position);
    }
}
