#include "SceneMgr.h"

void SceneMgr::AddScene(Scene* scene)
{
    if(scenes.contains(scene->name))
    {
        return;
    }
    scenes.emplace(scene->name, scene);
}

void SceneMgr::SelectScene(std::string name)
{
    activeScene->Destroy();
    activeScene = scenes.at(name);
    activeScene->Start();
}

void SceneMgr::Update(float fDeltaTime)
{
    activeScene->Update(fDeltaTime);
}
