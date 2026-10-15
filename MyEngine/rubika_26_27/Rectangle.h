#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "IDrawable.h"

class Rectangle : public IDrawable
{
public:
    Rectangle();
    void Start() override;
    void Update(float deltaTime) override;
    void Destroy() override;
    void SetTexture(const std::string& name);

    sf::RectangleShape rectangle;
};
