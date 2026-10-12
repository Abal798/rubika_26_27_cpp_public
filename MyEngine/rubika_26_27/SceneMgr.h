#pragma once
#include <map>
#include <set>

#include "Logger.h"
#include "Scene.h"


class SceneMgr : public IDebugable
{
public:
    SceneMgr();
    ~SceneMgr();
    
    std::map<std::string, Scene*> scenes;
    Scene* activeScene;
    
    bool AddScene(std::string name);
    bool AddScene(Scene* scene);
    void SelectScene(const std::string& name);
    void Update(float fDeltaTime);
    
    void DrawDebug() override;
    
    // debug
    
    char sceneName[64] = "";

};
