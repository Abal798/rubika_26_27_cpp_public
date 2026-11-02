#include "Rectangle.h"

#include "Globals.h"


Rectangle::Rectangle() : IDrawable(&rectangle)
{
}

void Rectangle::Start()
{
    rectangle.setFillColor(sf::Color::White);
}

void Rectangle::Update(float deltaTime)
{
}

void Rectangle::Destroy()
{
}

bool Rectangle::SetTexture(const std::string& name)
{
    if (&gData.TextureMgr->GetTextureData(name) == nullptr) return false;
    rectangle.setTexture(&gData.TextureMgr->GetTextureData(name).Texture);
    return true;
}

void Rectangle::SetSize(sf::Vector2f size)
{
    rectangle.setSize(size);
}
