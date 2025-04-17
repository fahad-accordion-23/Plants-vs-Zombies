#pragma once

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "AnimationController.h"

class Animation : public sf::Sprite, public AnimationController
{
private:
    sf::Rect<int> rect;

public:
    Animation() = delete;
    Animation(sf::Texture& texture, uint32_t total_frames, uint32_t start_frame, uint32_t end_frame, 
        uint32_t time_per_frame, uint32_t delay_before_start, uint32_t delay_after_end, 
        bool is_looping);

    /* Call every iteration */
    void update();
};
