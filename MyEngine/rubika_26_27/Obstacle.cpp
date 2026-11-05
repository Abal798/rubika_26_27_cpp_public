#include "Obstacle.h"

Obstacle::Obstacle()
{
    transform = AddComponent<TransformComponent>();
    renderer = AddComponent<RenderComponent>();
    dynamicCollideComponent = AddComponent<DynamicColliderComponent>();
}

Obstacle::~Obstacle()
{
}

void Obstacle::Start()
{
    Entity::Start();
    sprite = renderer->AddNewDrawable<Sprite>("Head", sf::Vector2f(-2.5f, -20), 0, sf::Vector2f(1, 1));
    sprite->SetVisibility(true);
    sprite->SetTexture("IsaacSprite");
    sprite->SetAnimation("Head_Down");
    
    dynamicCollideComponent->SetSize(sf::Vector2f(20, 20));
    dynamicCollideComponent->SetOffset(sf::Vector2f(5, -15));
}

void Obstacle::Update(float dt)
{
    Entity::Update(dt);
}
