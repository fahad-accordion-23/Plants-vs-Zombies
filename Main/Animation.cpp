#include "Animation.h"

Animation::Animation(sf::Texture& texture, uint32_t total_frames, uint32_t start_frame, uint32_t end_frame, 
    uint32_t time_per_frame, uint32_t delay_before_start, uint32_t delay_after_end, 
    bool is_looping)
    : Sprite(texture), 
    AnimationController(start_frame, end_frame, time_per_frame, delay_before_start, 
        delay_after_end, is_looping)
{
    rect.size.x = Sprite::getTexture().getSize().x / total_frames;
    rect.size.y = Sprite::getTexture().getSize().y;
    rect.position.x = 0;
    rect.position.y = 0;
}

void Animation::update()
{
    AnimationController::update();
    int frame = AnimationController::getCurrentFrame();

    if (frame == -1)
    {
        Sprite::setTextureRect({ { 0, 0 }, { 0, 0 } });
    }
    else
    {
        rect.position.x = rect.size.x * (frame - 1);
        Sprite::setTextureRect(rect);
    }
}
