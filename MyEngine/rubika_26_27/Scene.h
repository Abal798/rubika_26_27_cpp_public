#pragma once

#include <set>
#include <string>
#include <vector>

#include "Entity.h"

namespace sf
{
	class RenderWindow;
}

class Scene
{
public:
	std::string name;
	
	Scene(const std::string& name);
	~Scene() = default;

	virtual void Start();
	virtual void Update(float fDeltaTime);
	virtual void Destroy();

	virtual void AddEntity(Entity entity);
	virtual void RemoveEntity(Entity entity);
	
	/*
	 * This function will be removed later, when the rendering system will be more robust. But for now, we need it here.
	 * Function that will be called each frame to draw the entity
	*/
	void Draw(sf::RenderWindow& window) const;
	
private:
	std::vector<Entity> entities;
	
};

