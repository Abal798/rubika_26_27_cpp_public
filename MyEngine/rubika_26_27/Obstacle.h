#pragma once
#include "DynamicColliderComponent.h"
#include "Entity.h"
#include "Sprite.h"


class Obstacle : public Entity
{
public:
    Obstacle();
    ~Obstacle();
    
    
    void Start() override;
    void Update(float dt) override;
    
    private:
    TransformComponent* transform;
    RenderComponent* renderer;
    DynamicColliderComponent* dynamicCollideComponent;
    Sprite* sprite;

    
};
