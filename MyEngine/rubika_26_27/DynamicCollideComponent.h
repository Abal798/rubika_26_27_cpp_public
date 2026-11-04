#pragma once
#include <SfML/Graphics/Rect.hpp>

#include "IComponent.h"

class TransformComponent;

class DynamicCollideComponent : public IComponent
{
public:
    DynamicCollideComponent(Entity& entity);
    ~DynamicCollideComponent();
    
    virtual void Start() override;

    virtual void Update(float fDeltaTime) override;

    virtual void Destroy() override;
    
    void SetSize(sf::Vector2f size);
    void SetOffset(sf::Vector2f off);
    
private:
    TransformComponent* Transform;

    sf::FloatRect rect;
    sf::Vector2<float> offset;
};
