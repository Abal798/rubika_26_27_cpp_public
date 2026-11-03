#pragma once
#include <functional>
#include <map>
#include <string>
#include <SFML/Window/Keyboard.hpp>

#include "InputAction.h"

class InputMgr
{
public:
    InputMgr();
    ~InputMgr();
    
    void Init();
    void Destroy();
    void Update(float dt);
    
    bool CreateInputAction(std::string name);
    bool CreateInputAction(std::string name, sf::Keyboard::Key key);
    bool RemoveInputAction(std::string name);
    bool LinkKeyToAction(sf::Keyboard::Key key, std::string name);
    bool LinkKeyToAction(sf::Keyboard::Key key,  std::size_t hash);
    InputAction* FindInputAction(std::string name);
    InputAction* FindInputAction(std::size_t hash);
    
private:
    std::map<std::size_t, InputAction> actions;
    std::vector<std::pair<sf::Keyboard::Key, std::size_t>> keysActions;
};
