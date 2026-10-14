#include "Rectangle.h"


Rectangle::Rectangle() : IDrawable(&rectangle)
{
}

void Rectangle::Start()
{
    rectangle.setFillColor(sf::Color::Red);
}

void Rectangle::Update(float deltaTime)
{
}

void Rectangle::Destroy(float deltaTime)
{
}
