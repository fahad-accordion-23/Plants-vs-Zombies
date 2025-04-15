#include "NormalZombie.h"


NormalZombie::NormalZombie(Animation* anims[TOTAL_ANIMATIONS], sf::Vector2f position)
    : Zombie(animations, TOTAL_ANIMATIONS, WALK, position, { 144, 144 }, 10, 50, 0.5)
{
    active_animations[WALK] = true;

    animations[WALK] = new Animation(*anims[WALK]);
    animations[EAT] = new Animation(*anims[EAT]);
    animations[WALK_LOST_HEAD] = new Animation(*anims[WALK_LOST_HEAD]);
    animations[EAT_LOST_HEAD] = new Animation(*anims[EAT_LOST_HEAD]);
    animations[DIE_LOST_HEAD] = new Animation(*anims[DIE_LOST_HEAD]);
    animations[HEAD_FALL] = new Animation(*anims[HEAD_FALL]);
}

void NormalZombie::walk()
{
    if (current_state != WALK)
    {
        current_state = WALK;
        for (uint32_t i = 0; i < TOTAL_ANIMATIONS; i += 1)
            active_animations[i] = false;
        active_animations[WALK] = true;
        animations[WALK]->reset();
    }
    position.x -= distance_per_walk;
}

void NormalZombie::eat()
{
    if (current_state != EAT)
    {
        current_state = EAT;
        for (uint32_t i = 0; i < TOTAL_ANIMATIONS; i += 1)
            active_animations[i] = false;
        active_animations[EAT] = true;
        animations[EAT]->reset();
    }
}

bool NormalZombie::die()
{
    if (current_state != DIE_LOST_HEAD)
    {
        current_state = DIE_LOST_HEAD;
        for (uint32_t i = 0; i < TOTAL_ANIMATIONS; i += 1)
            active_animations[i] = false;
        active_animations[DIE_LOST_HEAD] = true;
        active_animations[HEAD_FALL] = true;
        active_animations[WALK_LOST_HEAD] = true;
        animations[DIE_LOST_HEAD]->reset();
        animations[HEAD_FALL]->reset();
        animations[WALK_LOST_HEAD]->reset();
    }
    if (active_animations[WALK_LOST_HEAD])
    {
        position.x -= distance_per_walk;
    }

    return animations[DIE_LOST_HEAD]->hasCompleted();
}

void NormalZombie::draw(sf::RenderWindow& window)
{
    if (animations[WALK_LOST_HEAD]->hasCompleted())
    {
        active_animations[WALK_LOST_HEAD] = false;
        animations[WALK_LOST_HEAD]->reset();
    }

    if (active_animations[HEAD_FALL])
    {
        active_animations[HEAD_FALL] = false;
        Zombie::draw(window);
        active_animations[HEAD_FALL] = true;

        Animation* anim = animations[HEAD_FALL];
        anim->draw(window, { position.x + 100 + anim->getTime() * distance_per_walk, position.y});
    }
    else
        Zombie::draw(window);
}
