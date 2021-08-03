#include "KeyboardHandler.hpp"
#include "Utils.hpp"

KeyboardHandler::KeyboardHandler() {

}

void KeyboardHandler::Press(SDL_Event e) {
    auto it = m_keys.find(Util::GetKeyCode(e));
    if (it != m_keys.end()) 
        it->second = true;
    else
        m_keys[Util::GetKeyCode(e)] = true;
}

void KeyboardHandler::Release(SDL_Event e) {
    auto it = m_keys.find(Util::GetKeyCode(e));
    if (it != m_keys.end()) 
        it->second = false;
    else 
        m_keys[Util::GetKeyCode(e)] = false;
}

bool KeyboardHandler::isPressed(SDL_KeyCode code) {
    auto it = m_keys.find(code);
    if (it != m_keys.end()) {
        return it->second;
    }
    return false;
}

bool KeyboardHandler::isReleased(SDL_KeyCode code) {
    return !isPressed(code);
}

KeyboardHandler::~KeyboardHandler() {

}