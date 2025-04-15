#include "Animation.h"

Animation::Animation(sf::Sprite& sprite, uint32_t number_of_sheets, uint32_t time_per_sheet, bool is_looping,
    uint32_t delay)
    : sprite(&sprite),
    number_of_sheets(number_of_sheets),
    time_per_sheet(time_per_sheet),
    is_looping(is_looping),
    current_sheet(0),
    time(0),
    has_completed(false),
    delay(delay)
{
    size = (sf::Vector2i)sprite.getTexture().getSize();
    size.x /= number_of_sheets;
}

bool Animation::draw(sf::RenderWindow& window, sf::Vector2f position)
{
    if (time < delay)
    {
        time += 1;
        return false;
    }

    sf::Vector2i sheet_position(current_sheet * size.x, 0);
    sf::Rect<int> rectangle(sheet_position, size);

    sprite->setTextureRect(rectangle);
    sprite->setPosition(position);
    window.draw(*sprite);

    time += 1;

    if (time == time_per_sheet + delay)
    {
        if (!has_completed)
        {
            time = delay;
            current_sheet += 1;
        }
        else
            time -= 1;

        if (current_sheet == number_of_sheets)
        {
            if (!is_looping)
            {
                current_sheet -= 1;
                has_completed = true;
            }
            else 
                current_sheet = 0;
        }
    }

    return has_completed;
}

bool Animation::hasCompleted()
{
    return has_completed;
}

void Animation::reset()
{
    current_sheet = 0;
    time = 0;
    has_completed = false;
}

uint32_t Animation::getTime()
{
    return time - delay;
}

sf::Vector2i Animation::getSize()
{
    return size;
}
