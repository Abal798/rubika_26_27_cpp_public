#include "Isaac.h"

#include "Sprite.h"

Isaac::Isaac()
{
    transform = AddComponent<TransformComponent>();
    renderer = AddComponent<RenderComponent>();
}

void Isaac::Start()
{
    Entity::Start();

    Sprite* body = renderer->AddNewDrawable<Sprite>("Body", sf::Vector2f(2, 0), 0, sf::Vector2f(1, 1));
    body->SetVisibility(true);
    body->SetTexture("IsaacSprite");
    body->SetAnimation("Body_Vertical");

    Sprite* headSprite = renderer->AddNewDrawable<Sprite>("Head", sf::Vector2f(-2.5f, -20), 0, sf::Vector2f(1, 1));
    headSprite->SetVisibility(true);
    headSprite->SetTexture("IsaacSprite");
    headSprite->SetAnimation("Head_Down");
}
