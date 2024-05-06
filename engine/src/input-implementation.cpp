#include "input-implementation.h"
#include <GLFW/glfw3.h>
#include <string>

InputImplementation::InputImplementation()
{
    std::memset(m_keyboardKeysPressed, false, sizeof(m_keyboardKeysPressed));
    std::memset(m_lastKeyboardKeysPressed, false, sizeof(m_lastKeyboardKeysPressed));
    std::memset(m_mouseButtonPressed, false, sizeof(m_mouseButtonPressed));
    std::memset(m_lastMouseButtonPressed, false, sizeof(m_lastMouseButtonPressed));
}

bool InputImplementation::IsKeyboardKeyJustPressed(KeyboardKey key) const
{
    return m_keyboardKeysPressed[static_cast<int>(key)] and not m_lastKeyboardKeysPressed[static_cast<int>(key)];
}

bool InputImplementation::IsKeyboardKeyJustReleased(KeyboardKey key) const
{
    return not m_keyboardKeysPressed[static_cast<int>(key)] and m_lastKeyboardKeysPressed[static_cast<int>(key)];
}

bool InputImplementation::IsKeyboardKeyPressed(KeyboardKey key) const
{
    return m_keyboardKeysPressed[static_cast<int>(key)];
}

bool InputImplementation::IsMouseButtonJustPressed(MouseButton button) const
{
    return m_mouseButtonPressed[static_cast<int>(button)] and not m_lastMouseButtonPressed[static_cast<int>(button)];
}

bool InputImplementation::IsMouseButtonJustReleased(MouseButton button) const
{
    return not m_mouseButtonPressed[static_cast<int>(button)] and m_lastMouseButtonPressed[static_cast<int>(button)];;
}

bool InputImplementation::IsMouseButtonPressed(MouseButton button) const
{
    return m_mouseButtonPressed[static_cast<int>(button)];
}

void InputImplementation::Process()
{
    const size_t keyboardKeysLength = sizeof(m_keyboardKeysPressed) / sizeof(m_keyboardKeysPressed[0]);
    const size_t mouseButtonsLength = sizeof(m_mouseButtonPressed) / sizeof(m_lastMouseButtonPressed[0]);

    std::copy(m_keyboardKeysPressed, m_keyboardKeysPressed + keyboardKeysLength, m_lastKeyboardKeysPressed);
    std::memset(m_keyboardKeysPressed, false, keyboardKeysLength);

    std::copy(m_mouseButtonPressed, m_mouseButtonPressed + mouseButtonsLength, m_lastMouseButtonPressed);
    std::memset(m_mouseButtonPressed, false, mouseButtonsLength);
}

void InputImplementation::UpdateKeyboardKeyState(KeyboardKey key, bool isPressed)
{
    m_keyboardKeysPressed[static_cast<int>(key)] = isPressed;
}

void InputImplementation::UpdateMouseButtonState(MouseButton button, bool isPressed)
{
    m_mouseButtonPressed[static_cast<int>(button)] = isPressed;
}
