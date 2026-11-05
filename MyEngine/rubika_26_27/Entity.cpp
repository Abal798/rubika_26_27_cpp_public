#include "Entity.h"

#include "DynamicColliderComponent.h"

Entity::Entity(std::string friendlyName)
{
}

Entity::~Entity()
{
    
}

void Entity::Start()
{
    for (auto element : components)
    {
        element->Start();
    }
}

void Entity::Update(float fDeltaTime)
{
    for (auto element : components)
    {
        element->Update(fDeltaTime);
    }
}

void Entity::Destroy()
{
    for (auto element : components)
    {
        element->Destroy();
    }
    delete this;
}


void Entity::Draw(sf::RenderWindow& window) const
{
    for (auto* element : components)
    {
        if (auto* drawable = dynamic_cast<RenderComponent*>(element))
        {
            drawable->Draw(window);
        }
        
#ifdef _DEBUG
        if (auto* col = dynamic_cast<DynamicColliderComponent*>(element))
        {
            if (col->showColliders)col->Draw(window);
        }
#endif
    }
}

bool Entity::operator==(const Entity& other) const
{
    return this == &other;
}

