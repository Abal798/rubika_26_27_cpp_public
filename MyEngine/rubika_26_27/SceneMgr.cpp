#include "SceneMgr.h"

#include "Globals.h"
#include "ImGui/imgui.h"


SceneMgr::SceneMgr()
{
    gData.DebugMgr->RegisterDebugableWindow("ScenesConsole", this);

}

SceneMgr::~SceneMgr()
{
    gData.DebugMgr->UnregisterDebugableWindow("ScenesConsole");

}

bool SceneMgr::AddScene(std::string name)
{
    Scene* newScene = new Scene(name);
    if (!AddScene(newScene))
    {
        delete newScene;
        return false;
    }
    return true;
}

bool SceneMgr::AddScene(Scene* scene)
{
    if(scenes.contains(scene->name))
    {
        return false;
    }
    scenes.emplace(scene->name, scene);
    return true;
}

void SceneMgr::SelectScene(const std::string& name)
{
    auto it = scenes.find(name);
    if (it == scenes.end()) return;

    if (activeScene) activeScene->Destroy();
    activeScene = it->second;
    activeScene->Start();
}

void SceneMgr::Update(float fDeltaTime)
{
    if (activeScene)activeScene->Update(fDeltaTime);
}

void SceneMgr::DrawDebug()
{
    ImGui::InputText("Scene Name", sceneName, IM_ARRAYSIZE(sceneName));

    if (ImGui::Button("Add/Select Scene"))
    {
        std::string sceneNameStr = sceneName; 

        if (!scenes.contains(sceneNameStr))
        {
            AddScene(sceneNameStr);
            Logger::Info("scene added : " + sceneNameStr);
        }
        
        SelectScene(sceneNameStr);
        Logger::Info("scene Selected : " + sceneNameStr);

        
        sceneName[0] = '\0';
    }

    if (ImGui::BeginTable("jsp", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings | ImGuiTableFlags_Borders))
    {
        ImGui::TableSetupColumn("scene Name");
        ImGui::TableSetupColumn("Entity Count");

        ImGui::TableHeadersRow();
        ImGui::TableNextRow();


        for (auto scene : scenes)
        {
            ImVec4 color = (scene.first == activeScene->name)
                ? ImVec4(0, 1, 0, 1)
                : ImVec4(1, 1, 1, 1);

            
            ImGui::TableSetColumnIndex(0);
            ImGui::TextColored(color, scene.first.c_str());
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%d Entities", scene.second->GetEntityCount());
            ImGui::TableNextRow();

        }

    }
    ImGui::EndTable();
    
    if (ImGui::Button("Add Entity On Active Scene"))
    {
        Entity* entity = activeScene->AddEntity();
        entity->AddComponent<TransformComponent>();
        RenderComponent* renderer = entity->AddComponent<RenderComponent>();
        renderer->AddDrawable<Rectangle>();
        entity->Start();
    }
}
