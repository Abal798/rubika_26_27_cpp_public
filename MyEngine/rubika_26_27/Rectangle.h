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
    bool SetTexture(const std::string& name);
    void SetSize(sf::Vector2f size);

    sf::RectangleShape rectangle;
};
