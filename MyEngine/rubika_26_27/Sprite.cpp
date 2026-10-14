#include "Sprite.h"

#include <SFML/Graphics/Texture.hpp>

sf::Texture tex;

Sprite::Sprite() : sprite(tex), IDrawable(& sprite)
{
}
