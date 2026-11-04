#pragma once
#include "Entity.h"
#include "Sprite.h"


class Isaac : public Entity
{
public:
    Isaac();
    ~Isaac();
    void Start() override;
    void Update(float dt) override;
    
    void GoUp(float dir);
    void GoDown(float dir);
    void GoLeft(float dir);
    void GoRight(float dir);
private:
    TransformComponent* transform;
    RenderComponent* renderer;
    
    const float ISAACSPEED = .3f;  
    Sprite* body;
    Sprite* headSprite;
    sf::Vector2<float> inputVector;
};
