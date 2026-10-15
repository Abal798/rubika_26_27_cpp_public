#include "Scene.h"

Scene::Scene(const std::string& name)
{
    this->name = name;
}

void Scene::Start()
{
}

void Scene::Update(float fDeltaTime)
{
}

void Scene::Destroy()
{
    for (Entity* entity : entities)
    {
        entity->Destroy();
    }
    entities.clear();
}

Entity* Scene::AddEntity()
{
    Entity* entity = new Entity();
    return AddEntity(entity);
}

Entity* Scene::AddEntity(Entity* entity)
{
    entities.push_back(entity);
    entity->Start();
    return entity;
}

void Scene::RemoveEntity(Entity* entity)
{
    std::erase(entities, entity);
    entity->Destroy();
}

int Scene::GetEntityCount()
{
    return entities.size();
}

void Scene::Draw(sf::RenderWindow& window) const
{
    for (Entity* entity : entities)
    {
        entity->Draw(window);
    }
}
