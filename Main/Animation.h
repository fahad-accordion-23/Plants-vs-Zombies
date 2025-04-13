#pragma once

#include <SFML/Graphics.hpp>

typedef unsigned int uint32_t;

class Animation
{
private:
    sf::RenderWindow* window;
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
    Animation(sf::RenderWindow& window, sf::Sprite& sprite, uint32_t number_of_sheets,
        uint32_t time_per_sheet, bool is_looping);

    bool draw(sf::Vector2f position);
};
