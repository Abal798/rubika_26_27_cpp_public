#include "Scene.h"

#include "Obstacle.h"

Scene::Scene(const std::string& name)
{
    this->name = name;
}

#include <random>

void Scene::Start()
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<float> dist(0.f, 500.f);

    for (int i = 0; i < 10; ++i)
    {
        float x = dist(rng);
        float y = dist(rng);

        Entity* entity = AddEntity(new Obstacle);
        entity->GetComponent<TransformComponent>()->SetWorldPosition(sf::Vector2f(x, y));
    }
}

void Scene::Update(float fDeltaTime)
{
    for (Entity* entity : entities)
    {
        entity->Update(fDeltaTime);
    }
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
