#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "IDrawable.h"

class Sprite : public IDrawable
{
public:
    Sprite();
    
    sf::Sprite sprite;
};
