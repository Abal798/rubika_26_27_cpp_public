#include "InputMgr.h"

InputMgr::InputMgr()
{
    Init();
}

InputMgr::~InputMgr()
{
}

void InputMgr::Init()
{
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
            FindInputAction(element.second)->SetValue(1);
        }
        else
        {
            FindInputAction(element.second)->SetValue(0);
        }
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
