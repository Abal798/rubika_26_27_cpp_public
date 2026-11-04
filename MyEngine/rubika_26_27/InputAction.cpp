#include "InputAction.h"

#include <utility>

InputAction::InputAction(const std::string& name)
{
    SetActionName(name);
}

void InputAction::SetActionName(const std::string& name)
{
    ActionName = name;
    ActionNameHash = std::hash<std::string>{}(name);
}

void InputAction::SetValue(float value)
{
    this->Value = value;
}

void InputAction::RegisterCallback(const std::string& debugName, std::function<void(float)> callback, void* owner)
{
    Callbacks.emplace_back(sCallbackInfo {.DebugName = debugName, .Callback = std::move(callback), .Owner = owner });
}

void InputAction::UnregisterCallbacks(void* owner)
{
    std::erase_if(Callbacks, [owner](const sCallbackInfo& info)
    {
        return info.Owner == owner;
    });
}

void InputAction::InvokeCallbacks(float value)
{
    for (auto element : Callbacks)
    {
        element.Callback(value);
    }
}

float InputAction::GetValue()
{
    return Value;
}

std::string InputAction::GetName()
{
    return ActionName;
}

int InputAction::GetCallbacksCount()
{
    return Callbacks.size();
}
