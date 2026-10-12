#pragma once
#include <map>
#include <set>
#include "Scene.h"


class SceneMgr
{
public:
    SceneMgr() = default;
    ~SceneMgr() = default;
    
    std::map<std::string, Scene*> scenes;
    Scene* activeScene;
    
    void AddScene(Scene* scene);
    void SelectScene(std::string name);
    void Update(float fDeltaTime);
};
