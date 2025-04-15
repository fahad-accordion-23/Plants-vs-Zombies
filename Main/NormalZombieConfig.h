#pragma once

typedef unsigned int uint32_t;

namespace NormalZombieConfig
{
    enum
    {
        WALK,
        EAT,
        WALK_LOST_HEAD,
        EAT_LOST_HEAD,
        DIE_LOST_HEAD,
        HEAD_FALL
    };

    constexpr uint32_t TOTAL_ANIMATIONS = 6;
    constexpr const char* P_WALK = "./assets/zombie/normal/walk.png";
    constexpr const char* P_EAT = "./assets/zombie/normal/eat.png";
    constexpr const char* P_WALK_LOST_HEAD = "./assets/zombie/normal/walk_lost_head.png";
    constexpr const char* P_EAT_LOST_HEAD = "./assets/zombie/normal/eat_lost_head.png";
    constexpr const char* P_DIE_LOST_HEAD = "./assets/zombie/normal/die_lost_head.png";
    constexpr const char* P_HEAD_FALL = "./assets/zombie/normal/head_fall.png";
}