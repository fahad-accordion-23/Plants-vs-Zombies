#include "ZombieFactory.h"

void ZombieFactory::initializeAssets()
{
    for (uint32_t i = 0; i < number_of_animations; i += 1)
    {
        if (!textures[i].loadFromFile(paths[i]))
        {
            std::cout << "Failed to load asset " << paths[i] << std::endl;
        }
        sprites[i] = new sf::Sprite(textures[i]);
    }
}

ZombieFactory::ZombieFactory(uint32_t number_of_animations)
    : number_of_animations(number_of_animations)
{
    paths = new const char*[number_of_animations];
    textures = new sf::Texture[number_of_animations];
    sprites = new sf::Sprite * [number_of_animations];
    animations = new Animation * [number_of_animations];
}

ZombieFactory::~ZombieFactory()
{
    delete[] paths;
    delete[] textures;
    for (uint32_t i = 0; i < number_of_animations; i += 1)
    {
        delete sprites[i];
    }
    delete[] sprites;
    delete[] animations;
}