#include "Zombie.h"

Zombie::Zombie()
{

}

Zombie::Zombie(Animation** animations, sf::FloatRect bounds)
    : animations(animations), bounds(bounds)
{
}

const sf::Rect<float> Zombie::getBounds()
{
    return bounds;
}
