#include "InputHandler.hpp"
#include "Utils.hpp"

InputHandler::InputHandler() {

}

void InputHandler::Press(SDL_Event e) {
    auto it = m_keys.find(Util::GetKeyCode(e));
    if (it != m_keys.end()) 
        it->second = true;
    else
        m_keys[Util::GetKeyCode(e)] = true;
}

void InputHandler::Release(SDL_Event e) {
    auto it = m_keys.find(Util::GetKeyCode(e));
    if (it != m_keys.end()) 
        it->second = false;
    else 
        m_keys[Util::GetKeyCode(e)] = false;
}

bool InputHandler::isPressed(SDL_KeyCode code) {
    auto it = m_keys.find(code);
    if (it != m_keys.end()) {
        return it->second;
    }
    return false;
}

bool InputHandler::isReleased(SDL_KeyCode code) {
    return !isPressed(code);
}

InputHandler::~InputHandler() {

}