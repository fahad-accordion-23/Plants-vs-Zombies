#include "NormalZombie.h"

NormalZombie::NormalZombie(Animation** animations, sf::FloatRect bounds)
    : Zombie(animations, bounds)
{
    animations[WALK][0].move(bounds.position);
    animations[EAT][0].move(bounds.position);
    animations[WALK_DIE][0].move(bounds.position);
    animations[WALK_DIE][1].move(bounds.position);
    animations[WALK_DIE][2].move(bounds.position);
    animations[EAT_DIE][0].move(bounds.position);
    animations[EAT_DIE][1].move(bounds.position);
    animations[EAT_DIE][2].move(bounds.position);

    move_distance = NormalZombieConfig::move_distance;
    state = WALK;
    setState(WALK);
}

NormalZombie::~NormalZombie()
{
    delete[] animations[0];
    delete[] animations[1];
    delete[] animations[2];
    delete[] animations[3];
}

void NormalZombie::draw(sf::RenderWindow& window)
{
    if (state == WALK)
        window.draw(animations[WALK][0]);
    else if (state == EAT)
        window.draw(animations[EAT][0]);
    else if (state == WALK_DIE)
    {
        window.draw(animations[WALK_DIE][0]);
        window.draw(animations[WALK_DIE][1]);
        window.draw(animations[WALK_DIE][2]);
    }
    else if (state == EAT_DIE)
    {
        window.draw(animations[EAT_DIE][0]);
        window.draw(animations[EAT_DIE][1]);
        window.draw(animations[EAT_DIE][2]);
    }
}

void NormalZombie::update()
{
    if (state == WALK)
        animations[WALK][0].update();
    else if (state == EAT)
        animations[EAT][0].update();
    else if (state == WALK_DIE)
    {
        animations[WALK_DIE][1].move({ -move_distance, 0 });

        animations[WALK_DIE][0].update();
        animations[WALK_DIE][1].update();
        animations[WALK_DIE][2].update();
    }
    else if (state == EAT_DIE)
    {
        animations[EAT_DIE][0].update();
        animations[EAT_DIE][1].update();
        animations[EAT_DIE][2].update();
    }
}

void NormalZombie::setState(uint32_t state)
{
    this->state = state;

    animations[WALK][0].pause();
    animations[EAT][0].pause();
    animations[WALK_DIE][0].pause();
    animations[WALK_DIE][1].pause();
    animations[WALK_DIE][2].pause();
    animations[EAT_DIE][0].pause();
    animations[EAT_DIE][1].pause();
    animations[EAT_DIE][2].pause();

    if (state == WALK)
        animations[WALK][0].play();
    else if (state == EAT)
        animations[EAT][0].play();
    else if (state == WALK_DIE)
    {
        animations[WALK_DIE][0].play();
        animations[WALK_DIE][1].play();
        animations[WALK_DIE][2].play();
    }
    else if (state == EAT_DIE)
    {
        animations[EAT_DIE][0].play();
        animations[EAT_DIE][1].play();
        animations[EAT_DIE][2].play();
    }
}

void NormalZombie::walk()
{
    setState(WALK);

    bounds.position.x -= move_distance;
    animations[WALK][0].move({ -move_distance, 0 });
    animations[EAT][0].move({ -move_distance, 0 });
    animations[WALK_DIE][0].move({ -move_distance, 0 });
    animations[WALK_DIE][1].move({ -move_distance, 0 });
    animations[WALK_DIE][2].move({ -move_distance, 0 });
    animations[EAT_DIE][0].move({ -move_distance, 0 });
    animations[EAT_DIE][1].move({ -move_distance, 0 });
    animations[EAT_DIE][2].move({ -move_distance, 0 });
}

void NormalZombie::eat()
{
    setState(EAT);
}

void NormalZombie::die()
{
    if (state == WALK)
        setState(WALK_DIE);
    else if (state == EAT)
        setState(EAT_DIE);
}