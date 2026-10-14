#include "Entity.h"

Entity::Entity(std::string friendlyName) : transform(*this)
{
}

Entity::~Entity()
{
    
}

void Entity::Start()
{
    transform.SetWorldPosition(sf::Vector2(100.f,100.f));
}

void Entity::Update(float fDeltaTime)
{
    render.Draw(fDeltaTime);
}

void Entity::Destroy()
{
    delete this;
}

void Entity::Draw(sf::RenderWindow& window) const
{
}

bool Entity::operator==(const Entity& other) const
{
    return this == &other;
}

