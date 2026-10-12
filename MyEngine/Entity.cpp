#include "Entity.h"

Entity::Entity(std::string friendlyName)
{
}

Entity::~Entity()
{
}

void Entity::Start()
{
}

void Entity::Update(float fDeltaTime)
{
}

void Entity::Destroy()
{
}

void Entity::Draw(sf::RenderWindow& window) const
{
}

bool Entity::operator==(const Entity& other) const
{
    return this == &other;
}

