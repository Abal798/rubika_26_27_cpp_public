#pragma once
#include "Entity.h"

class Isaac : public Entity
{
public:
    Isaac();
    void Start() override;
    void GoUp(float dir);
private:
    TransformComponent* transform;
    RenderComponent* renderer;
};
