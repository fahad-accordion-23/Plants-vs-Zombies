#include "NormalZombieFactory.h"

void NormalZombieFactory::initializeAssets()
{
    paths[WALK] = P_WALK;
    paths[EAT] = P_EAT;
    paths[WALK_LOST_HEAD] = P_WALK_LOST_HEAD;
    paths[EAT_LOST_HEAD] = P_EAT_LOST_HEAD;
    paths[DIE_LOST_HEAD] = P_DIE_LOST_HEAD;
    paths[HEAD_FALL] = P_HEAD_FALL;

    ZombieFactory::initializeAssets();
}

void NormalZombieFactory::initializeAnimations()
{
    animations[WALK] = new Animation(*sprites[WALK], 22, 5, true);
    animations[EAT] = new Animation(*sprites[EAT], 21, 5, true);
    animations[WALK_LOST_HEAD] = new Animation(*sprites[WALK_LOST_HEAD], 18, 2, false);
    animations[EAT_LOST_HEAD] = new Animation(*sprites[EAT_LOST_HEAD], 11, 5, false);
    animations[DIE_LOST_HEAD] = new Animation(*sprites[DIE_LOST_HEAD], 10, 10, false, 18 * 2);
    animations[HEAD_FALL] = new Animation(*sprites[HEAD_FALL], 12, 10, false);
}

NormalZombieFactory::NormalZombieFactory()
    : ZombieFactory(TOTAL_ANIMATIONS)
{
    initializeAssets();
    initializeAnimations(); // Memory allocating
}

NormalZombieFactory::~NormalZombieFactory()
{
    for (int i = 0; i < TOTAL_ANIMATIONS; i++)
        delete animations[i];
}

Zombie* NormalZombieFactory::createZombie(sf::Vector2f position)
{
    return new NormalZombie(animations, position);
}
