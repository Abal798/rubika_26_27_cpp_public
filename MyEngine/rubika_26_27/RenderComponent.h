#pragma once
#include <vector>

#include "IComponent.h"
#include "IDrawable.h"
#include "Rectangle.h"

class RenderComponent : public IComponent
{
public:
    RenderComponent(Entity& entity);
    ~RenderComponent() = default;
    
    std::vector<IDrawable*> drawables;
    void Draw(sf::RenderWindow& window) const;
    
    void Start() override;
    void Update(float fDeltaTime) override;
    void Destroy() override;
    
    template <typename D>
    D* AddDrawable();
};

template <typename D>
D* RenderComponent::AddDrawable()
{
    D* drawable = new D();
    drawables.push_back(drawable);
    return drawable;
}


