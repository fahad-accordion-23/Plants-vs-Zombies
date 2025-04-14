#pragma once

#include <SFML/Graphics.hpp>

typedef unsigned int uint32_t;

class Animation
{
private:
    sf::Sprite* sprite;
    uint32_t number_of_sheets;
    uint32_t current_sheet;
    uint32_t time_per_sheet;
    uint32_t time;
    sf::Vector2i size;
    bool is_looping;
    bool has_completed;

public:
    Animation() = delete;
    Animation(sf::Sprite& sprite, uint32_t number_of_sheets, uint32_t time_per_sheet,
        bool is_looping);
    Animation(const Animation& other) = default;

    bool draw(sf::RenderWindow& window, sf::Vector2f position);
    bool hasCompleted();
    void reset();
    sf::Vector2i getSize();
};
