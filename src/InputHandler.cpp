#include "InputHandler.hpp"
#include "Utils.hpp"

void InputHandler::PressKey(const SDL_Event& e) {
    auto it = m_keys.find(Util::GetKeyCode(e));
    if (it != m_keys.end()) 
        it->second = true;
    else
        m_keys[Util::GetKeyCode(e)] = true;
}

void InputHandler::ReleaseKey(const SDL_Event& e) {
    auto it = m_keys.find(Util::GetKeyCode(e));
    if (it != m_keys.end()) 
        it->second = false;
    else 
        m_keys[Util::GetKeyCode(e)] = false;
}

void InputHandler::PressMouseButton(const SDL_Event& e) {
    auto it = m_buttons.find(e.button.button);
    if (it != m_buttons.end()) 
        it->second = true;
    else 
        m_keys[e.button.button] = true;
}

void InputHandler::ReleaseMouseButton(const SDL_Event& e) {
    auto it = m_buttons.find(e.button.button);
    if (it != m_buttons.end()) 
        it->second = false;
    else 
        m_keys[e.button.button] = false;
}

bool InputHandler::isPressed(const SDL_KeyCode& code) {
    auto it = m_keys.find(code);
    if (it != m_keys.end()) {
        return it->second;
    }
    return false;
}

bool InputHandler::isReleased(const SDL_KeyCode& code) {
    return !isPressed(code);
}

bool InputHandler::isMouseButtonPressed(ubyte code) {
    auto it = m_keys.find(code);
    if (it != m_keys.end()) {
        return it->second;
    }
    return false;
}

bool InputHandler::isMouseButtonReleased(ubyte code) {
    return !isMouseButtonPressed(code);
}
