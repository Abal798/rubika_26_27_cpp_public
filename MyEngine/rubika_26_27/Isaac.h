#pragma once
#include "Entity.h"

class Isaac : public Entity
{
public:
    Isaac();
    void Start() override;
    
private:
    TransformComponent* transform;
    RenderComponent* renderer;
};
