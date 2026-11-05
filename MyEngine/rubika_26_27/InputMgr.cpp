#include "InputMgr.h"

#include <cassert>

#include "Globals.h"
#include "ImGui/imgui.h"

InputMgr::InputMgr()
{
    gData.DebugMgr->RegisterDebugableWindow("Inputs", this);

}

InputMgr::~InputMgr()
{
    gData.DebugMgr->UnregisterDebugableWindow("Inputs");

}

void InputMgr::Init()
{
#ifdef _DEBUG
    assert(CreateInputAction("up", sf::Keyboard::Key::Up) == true);
    assert(CreateInputAction("down", sf::Keyboard::Key::Down) == true);
    assert(CreateInputAction("left", sf::Keyboard::Key::Left) == true);
    assert(CreateInputAction("right", sf::Keyboard::Key::Right) == true);
#else
    CreateInputAction("up", sf::Keyboard::Key::Up);
    CreateInputAction("down", sf::Keyboard::Key::Down);
    CreateInputAction("left", sf::Keyboard::Key::Left);
    CreateInputAction("right", sf::Keyboard::Key::Right);
#endif
}

void InputMgr::Destroy()
{
    delete(this);
}

void InputMgr::Update(float dt)
{
    for (auto &element : keysActions)
    {
        if (sf::Keyboard::isKeyPressed(element.first))
        {
            InputAction* action = FindInputAction(element.second);
            action->SetValue(1);
            action->InvokeCallbacks(action->GetValue());
        }
        else
        {
            FindInputAction(element.second)->SetValue(0);
        }
    }
}

void InputMgr::DrawDebug()
{
    
    
    if (ImGui::BeginTable("jsp", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings | ImGuiTableFlags_Borders))
    {
        ImGui::TableSetupColumn("input name");
        ImGui::TableSetupColumn("CallBacks");
        ImGui::TableHeadersRow();
        ImGui::TableNextRow();

        for (auto element : keysActions)
        {
            ImGui::TableSetColumnIndex(0);
            ImGui::Text( FindInputAction(element.second)->GetName().c_str());
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%d callBacks" , FindInputAction(element.second)->GetCallbacksCount());
            ImGui::TableNextRow();
        }
        
        ImGui::EndTable();
    }
}

bool InputMgr::CreateInputAction(std::string name)
{
    InputAction action = InputAction(name);
    size_t key = std::hash<std::string>{}(name);
    auto ret = actions.emplace(key, action);
    return ret.second;
}

bool InputMgr::CreateInputAction(std::string name, sf::Keyboard::Key key)
{
    if (CreateInputAction(name))
    {
        if (LinkKeyToAction(key, name))
        {
            return true;
        }
    }
    return false;
}

bool InputMgr::RemoveInputAction(std::string name)
{
    if (actions.find(std::hash<std::string>{}(name)) != actions.end())
    {
        actions.erase(std::hash<std::string>{}(name));
        return true;
    }
    return false;
}

bool InputMgr::LinkKeyToAction(sf::Keyboard::Key key, std::string name)
{
    InputAction* action = FindInputAction(name);
    if (action)
    {
        keysActions.emplace_back(key, std::hash<std::string>{}(name));
        return true;
    }
    return false;
}

bool InputMgr::LinkKeyToAction(sf::Keyboard::Key key,  std::size_t hash)
{
    auto ret = keysActions.emplace_back(key, hash);
    return ret.second;
}

InputAction* InputMgr::FindInputAction(std::string name)
{
    return &actions[std::hash<std::string>{}(name)];
}

InputAction* InputMgr::FindInputAction(std::size_t hash)
{
    return &actions[hash];
}
