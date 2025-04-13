#include "Animation.h"

Animation::Animation(sf::RenderWindow& window, sf::Sprite& sprite, uint32_t number_of_sheets, 
    uint32_t time_per_sheet, bool is_looping)
    : window(&window), 
    sprite(&sprite),
    number_of_sheets(number_of_sheets), 
    time_per_sheet(time_per_sheet), 
    is_looping(is_looping), 
    current_sheet(0),
    time(0),
    has_completed(false)
{
    size = (sf::Vector2i)sprite.getTexture().getSize();
    size.x /= number_of_sheets;
}

bool Animation::draw(sf::Vector2f position)
{
    sf::Vector2i sheet_position(current_sheet * size.x, 0);
    sf::Rect<int> rectangle(sheet_position, size);

    sprite->setTextureRect(rectangle);
    sprite->setPosition(position);
    window->draw(*sprite);

    time += 1;

    if (time == time_per_sheet)
    {
        time = 0;

        if (!has_completed)
            current_sheet += 1;

        if (current_sheet == number_of_sheets)
        {
            if (!is_looping)
                has_completed = true;

            current_sheet = 0;
        }
    }

    return has_completed;
}
