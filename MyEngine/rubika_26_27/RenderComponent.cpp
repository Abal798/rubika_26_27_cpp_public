#include "RenderComponent.h"

#include "Entity.h"
#include "TransformComponent.h"

RenderComponent::RenderComponent(Entity& entity) : IComponent(entity)
{
    this->entity = &entity; 
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
    TransformComponent* transform = entity->GetComponent<TransformComponent>();
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
