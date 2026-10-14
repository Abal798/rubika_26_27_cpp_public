#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "IDrawable.h"

class Rectangle : public IDrawable
{
public:
    Rectangle();
    void Start() override;
    void Update(float deltaTime) override;
    void Destroy(float deltaTime) override;

    sf::RectangleShape rectangle;
};
