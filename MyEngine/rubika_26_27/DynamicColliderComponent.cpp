#include "DynamicColliderComponent.h"
#include <Entity.h>

DynamicColliderComponent::DynamicColliderComponent(Entity& entity) : IComponent(entity)
{
#ifdef _DEBUG
    
    rectDebug = sf::RectangleShape(sf::Vector2f(rect.size));
    
#endif

}

DynamicColliderComponent::~DynamicColliderComponent()
{
}

void DynamicColliderComponent::Start()
{
    Transform = GetEntity().GetComponent<TransformComponent>();
    
#ifdef _DEBUG

    rectDebug.setFillColor(sf::Color::Green);
    rectDebug.setSize(rect.size);
    
#endif
}

void DynamicColliderComponent::Update(float fDeltaTime)
{
    rect.position = Transform->GetWorldPosition() + offset;
}

void DynamicColliderComponent::Destroy()
{
}

void DynamicColliderComponent::SetSize(sf::Vector2f size)
{
    rect.size = size;
}

void DynamicColliderComponent::SetOffset(sf::Vector2f off)
{
    offset = off;
}


#ifdef _DEBUG

void DynamicColliderComponent::Draw(sf::RenderWindow& window)
{
    rectDebug.setSize(rect.size);
    rectDebug.setPosition(rect.position);
    
    sf::RenderStates states = sf::RenderStates::Default;
    sf::Transform transform;
    //transform.translate(rect.position);
    states.transform = transform;
    window.draw(rectDebug, states);
}

#endif
