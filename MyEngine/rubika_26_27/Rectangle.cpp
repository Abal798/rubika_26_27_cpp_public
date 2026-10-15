#include "Rectangle.h"

#include "Globals.h"


Rectangle::Rectangle() : IDrawable(&rectangle)
{
}

void Rectangle::Start()
{
    rectangle.setFillColor(sf::Color::White);
    SetTexture("IsaacSprite");
    rectangle.setSize(sf::Vector2f(200.f, 200.f));
}

void Rectangle::Update(float deltaTime)
{
}

void Rectangle::Destroy()
{
}

void Rectangle::SetTexture(const std::string& name)
{
    rectangle.setTexture(&gData.TextureMgr->GetTextureData(name).Texture);
}
