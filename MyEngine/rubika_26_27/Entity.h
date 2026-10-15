#pragma once

#include <string>

#include "RenderComponent.h"
#include "TransformComponent.h"

namespace sf
{
	class RenderWindow;
}

class Entity
{
public:
	Entity(std::string friendlyName = "");
	virtual ~Entity();
	
	virtual void Start();
	virtual void Update(float fDeltaTime);
	virtual void Destroy();
	
	template <typename C>
	C* AddComponent();

	template <typename C>
	C* GetComponent() const;
	
	
	void Draw(sf::RenderWindow& window) const;
	
	bool operator==(const Entity&) const;
	std::vector<IComponent*> components; 
};

template <typename C>
C* Entity::AddComponent()
{
	if (GetComponent<C>() == nullptr)
	{
		C* component = new C(*this);
		components.push_back(component);
		return component;
	}
	return nullptr;
}

template <typename C>
C* Entity::GetComponent() const
{
	for (auto element : components)
	{
		if (auto* component = dynamic_cast<C*>(element))
		{
			return component;
		}
	}
	return nullptr;
}
