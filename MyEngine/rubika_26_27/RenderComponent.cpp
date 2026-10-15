#include "RenderComponent.h"

RenderComponent::RenderComponent(Entity& entity) : IComponent(entity)
{
}

void RenderComponent::Draw(sf::RenderWindow& window) const
{
    for (auto element : drawables)
    {
        element->Draw(window);
    }
}

void RenderComponent::Start()
{
    for (auto element : drawables)
    {
        element->Start();
    }
}

void RenderComponent::Update(float fDeltaTime)
{
    for (auto element : drawables)
    {
        element->Update(fDeltaTime);
    }
}

void RenderComponent::Destroy()
{
    for (auto element : drawables)
    {
        element->Destroy();
    }
}
