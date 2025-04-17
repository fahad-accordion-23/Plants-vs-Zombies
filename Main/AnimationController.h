#pragma once

#include <cstdint>

class AnimationController
{
private:
    int current_frame;
    uint32_t start_frame;
    uint32_t end_frame;
    uint32_t internal_time;         // internal clock which is updated every update() call
    uint32_t time_per_frame;        // internal time units to spend per frame
    uint32_t delay_before_start;
    uint32_t delay_after_end;
    bool has_started;
    bool is_playing;
    bool is_looping;
    bool has_finished;

public:
    AnimationController();
    AnimationController(uint32_t start_frame, uint32_t end_frame, uint32_t time_per_frame, 
        uint32_t delay_before_start, uint32_t delay_after_end, bool is_looping);

    void start();
    void play();
    void pause();
    void reset();
    void update();
    void setLooping(bool is_looping);
    int getCurrentFrame();
};