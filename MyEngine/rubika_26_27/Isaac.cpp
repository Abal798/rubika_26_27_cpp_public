#include "Isaac.h"

#include "Globals.h"
#include "Logger.h"

Isaac::Isaac()
{
    transform = AddComponent<TransformComponent>();
    renderer = AddComponent<RenderComponent>();
    dynamicCollideComponent = AddComponent<DynamicColliderComponent>();
}

Isaac::~Isaac()
{
    gData.InputMgr->FindInputAction("up")->UnregisterCallbacks(this);
    gData.InputMgr->FindInputAction("down")->UnregisterCallbacks(this);
    gData.InputMgr->FindInputAction("left")->UnregisterCallbacks(this);
    gData.InputMgr->FindInputAction("right")->UnregisterCallbacks(this);
}

void Isaac::Start()
{
    Entity::Start();

    body = renderer->AddNewDrawable<Sprite>("Body", sf::Vector2f(2, 0), 0, sf::Vector2f(1, 1));
    body->SetVisibility(true);
    body->SetTexture("IsaacSprite");
    body->SetAnimation("Body_Vertical");

    headSprite = renderer->AddNewDrawable<Sprite>("Head", sf::Vector2f(-2.5f, -20), 0, sf::Vector2f(1, 1));
    headSprite->SetVisibility(true);
    headSprite->SetTexture("IsaacSprite");
    headSprite->SetAnimation("Head_Down");
    
    gData.InputMgr->FindInputAction("up")->RegisterCallback("isaacGoUp",[this](float f){this->GoUp(f);}, this);
    gData.InputMgr->FindInputAction("down")->RegisterCallback("isaacGoDown",[this](float f){this->GoDown(f);}, this);
    gData.InputMgr->FindInputAction("left")->RegisterCallback("isaacGoLeft",[this](float f){this->GoLeft(f);}, this);
    gData.InputMgr->FindInputAction("right")->RegisterCallback("isaacGoRight",[this](float f){this->GoRight(f);}, this);
    
    dynamicCollideComponent->SetSize(sf::Vector2f(10, 20));
    dynamicCollideComponent->SetOffset(sf::Vector2f(6, -10));
}

void Isaac::Update(float dt)
{
    Entity::Update(dt);
    
    sf::Vector2<float> pos = transform->GetWorldPosition();
    if (inputVector.x != 0 && inputVector.y != 0)inputVector = inputVector.normalized() *  ISAACSPEED;
    pos += inputVector;
    transform->SetWorldPosition(pos);

    
    inputVector = sf::Vector2<float>(0,0);
}

void Isaac::GoUp(float dir)
{
    inputVector.y -= dir * ISAACSPEED;
    body->SetAnimation("Body_Vertical");
    headSprite->SetAnimation("Head_Up");

}

void Isaac::GoDown(float dir)
{
    inputVector.y += dir * ISAACSPEED;
    body->SetAnimation("Body_Vertical");
    headSprite->SetAnimation("Head_Down");

}

void Isaac::GoLeft(float dir)
{
    inputVector.x -= dir * ISAACSPEED;
    body->SetAnimation("Body_Left");
    headSprite->SetAnimation("Head_Left");

}

void Isaac::GoRight(float dir)
{
    inputVector.x += dir * ISAACSPEED;
    body->SetAnimation("Body_Right");
    headSprite->SetAnimation("Head_Right");

}
