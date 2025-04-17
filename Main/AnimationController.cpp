#include "AnimationController.h"

AnimationController::AnimationController()
    : current_frame(-1),
    start_frame(0),
    end_frame(0),
    internal_time(0),
    time_per_frame(0),
    delay_before_start(0),
    delay_after_end(0),
    has_started(false),
    is_playing(false),
    is_looping(false),
    has_finished(false)
{
}

AnimationController::AnimationController(uint32_t start_frame, uint32_t end_frame, 
    uint32_t time_per_frame, uint32_t delay_before_start, uint32_t delay_after_end, 
    bool is_looping)
    : current_frame(-1),
    start_frame(start_frame),
    end_frame(end_frame),
    internal_time(0),
    time_per_frame(time_per_frame),
    delay_before_start(delay_before_start),
    delay_after_end(delay_after_end),
    has_started(false),
    is_playing(false),
    is_looping(is_looping),
    has_finished(false)
{
}

void AnimationController::start()
{
    reset();
    play();
}

void AnimationController::play()
{
    is_playing = true;
}

void AnimationController::pause()
{
    is_playing = false;
}

void AnimationController::update()
{
    if (!is_playing)
        return;

    internal_time += 1;

    /* delay before start */
    if (!has_started)
    {
        if (internal_time >= delay_before_start)
        {
            internal_time -= delay_before_start;
            current_frame = start_frame;
            has_started = true;
        }
    }
    
    /* delay after end */
    else if (has_finished)
    {
        if (internal_time >= delay_after_end)
        {
            internal_time -= delay_after_end;
            current_frame = -1;
            is_playing = false;
        }
    }

    /* normal frame progression */
    else if (internal_time >= time_per_frame)
    {
        if (current_frame < end_frame)
            current_frame += 1;
        else if (is_looping)
            current_frame = start_frame;
        else
            has_finished = true;

        internal_time -= time_per_frame;
    }
}

void AnimationController::setLooping(bool is_looping)
{
    this->is_looping = is_looping;
}

int AnimationController::getCurrentFrame()
{
    return current_frame;
}

void AnimationController::reset()
{
    *this = AnimationController();
}

