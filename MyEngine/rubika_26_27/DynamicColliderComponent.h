#pragma once
#include <SfML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "IComponent.h"

class TransformComponent;

class DynamicColliderComponent : public IComponent
{
public:
    enum class OnCollisionChoice
    {
        Ignore,
        Block,
    };
    
    DynamicColliderComponent(Entity& entity);
    ~DynamicColliderComponent();
    
    virtual void Start() override;

    virtual void Update(float fDeltaTime) override;

    virtual void Destroy() override;
    
    void SetSize(sf::Vector2f size);
    void SetOffset(sf::Vector2f off);
    
    void EnableCollision(bool bEnable);
    bool AreCollisionsEnabled() const;

    const sf::FloatRect& GetHitbox() const;
    
    //void SetOnCollisionCallback(std::function<OnCollisionChoice(const Entity*)> callback);

    
#ifdef _DEBUG
    bool showColliders;
    
    sf::RectangleShape rectDebug;
    
    void Draw(sf::RenderWindow& window);
    
#endif
    
private:
    TransformComponent* Transform;

    sf::FloatRect rect;
    sf::Vector2<float> offset;
};
