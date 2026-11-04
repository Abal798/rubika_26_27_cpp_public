#include "DynamicCollideComponent.h"
#include <Entity.h>

DynamicCollideComponent::DynamicCollideComponent(Entity& entity) : IComponent(entity)
{
}

DynamicCollideComponent::~DynamicCollideComponent()
{
}

void DynamicCollideComponent::Start()
{
    Transform = GetEntity().GetComponent<TransformComponent>();

}

void DynamicCollideComponent::Update(float fDeltaTime)
{
    rect.position = Transform->GetWorldPosition() + offset;
}

void DynamicCollideComponent::Destroy()
{
}

void DynamicCollideComponent::SetSize(sf::Vector2f size)
{
    rect.size = size;
}

void DynamicCollideComponent::SetOffset(sf::Vector2f off)
{
    offset = off;
}
