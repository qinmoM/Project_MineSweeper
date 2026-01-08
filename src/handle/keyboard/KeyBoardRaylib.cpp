#include "KeyboardRaylib.h"

bool KeyboardRaylib::keyDown(Base::Key key) const
{
    return IsKeyDown(mapKey(key));
}

bool KeyboardRaylib::keyPressed(Base::Key key) const
{
    return IsKeyPressed(mapKey(key));
}

bool KeyboardRaylib::keyReleased(Base::Key key) const
{
    return IsKeyReleased(mapKey(key));
}

KeyboardKey KeyboardRaylib::mapKey(Base::Key key) const
{
    switch (key)
    {
    case Base::Key::Unknown: return KEY_NULL;
    case Base::Key::A: return KEY_A;
    case Base::Key::B: return KEY_B;
    case Base::Key::C: return KEY_C;
    case Base::Key::D: return KEY_D;
    case Base::Key::E: return KEY_E;
    case Base::Key::F: return KEY_F;
    case Base::Key::G: return KEY_G;
    case Base::Key::H: return KEY_H;
    case Base::Key::I: return KEY_I;
    case Base::Key::J: return KEY_J;
    case Base::Key::K: return KEY_K;
    case Base::Key::L: return KEY_L;
    case Base::Key::M: return KEY_M;
    case Base::Key::N: return KEY_N;
    case Base::Key::O: return KEY_O;
    case Base::Key::P: return KEY_P;
    case Base::Key::Q: return KEY_Q;
    case Base::Key::R: return KEY_R;
    case Base::Key::S: return KEY_S;
    case Base::Key::T: return KEY_T;
    case Base::Key::U: return KEY_U;
    case Base::Key::V: return KEY_V;
    case Base::Key::W: return KEY_W;
    case Base::Key::X: return KEY_X;
    case Base::Key::Y: return KEY_Y;
    case Base::Key::Z: return KEY_Z;
    case Base::Key::Num1: return KEY_ONE;
    case Base::Key::Num2: return KEY_TWO;
    case Base::Key::Num3: return KEY_THREE;
    case Base::Key::Num4: return KEY_FOUR;
    case Base::Key::Num5: return KEY_FIVE;
    case Base::Key::Num6: return KEY_SIX;
    case Base::Key::Num7: return KEY_SEVEN;
    case Base::Key::Num8: return KEY_EIGHT;
    case Base::Key::Num9: return KEY_NINE;
    case Base::Key::Num0: return KEY_ZERO;
    case Base::Key::Hyphen: return KEY_MINUS;
    case Base::Key::Equal: return KEY_EQUAL;
    case Base::Key::LBracket: return KEY_LEFT_BRACKET;
    case Base::Key::RBracket: return KEY_RIGHT_BRACKET;
    case Base::Key::Backslash: return KEY_BACKSLASH;
    case Base::Key::Semicolon: return KEY_SEMICOLON;
    case Base::Key::Apostrophe: return KEY_APOSTROPHE;
    case Base::Key::Grave: return KEY_GRAVE;
    case Base::Key::Comma: return KEY_COMMA;
    case Base::Key::Period: return KEY_PERIOD;
    case Base::Key::Slash: return KEY_SLASH;
    case Base::Key::F1: return KEY_F1;
    case Base::Key::F2: return KEY_F2;
    case Base::Key::F3: return KEY_F3;
    case Base::Key::F4: return KEY_F4;
    case Base::Key::F5: return KEY_F5;
    case Base::Key::F6: return KEY_F6;
    case Base::Key::F7: return KEY_F7;
    case Base::Key::F8: return KEY_F8;
    case Base::Key::F9: return KEY_F9;
    case Base::Key::F10: return KEY_F10;
    case Base::Key::F11: return KEY_F11;
    case Base::Key::F12: return KEY_F12;
    case Base::Key::PrintScreen: return KEY_PRINT_SCREEN;
    case Base::Key::ScrollLock: return KEY_SCROLL_LOCK;
    case Base::Key::Pause: return KEY_PAUSE;
    case Base::Key::Insert: return KEY_INSERT;
    case Base::Key::Home: return KEY_HOME;
    case Base::Key::PageUp: return KEY_PAGE_UP;
    case Base::Key::Delete: return KEY_DELETE;
    case Base::Key::End: return KEY_END;
    case Base::Key::PageDown: return KEY_PAGE_DOWN;
    case Base::Key::Up: return KEY_UP;
    case Base::Key::Down: return KEY_DOWN;
    case Base::Key::Left: return KEY_LEFT;
    case Base::Key::Right: return KEY_RIGHT;
    case Base::Key::Escape: return KEY_ESCAPE;
    case Base::Key::Tab: return KEY_TAB;
    case Base::Key::CapsLock: return KEY_CAPS_LOCK;
    case Base::Key::ShiftLeft: return KEY_LEFT_SHIFT;
    case Base::Key::CtrlLeft: return KEY_LEFT_CONTROL;
    case Base::Key::Backspace: return KEY_BACKSPACE;
    case Base::Key::Enter: return KEY_ENTER;
    case Base::Key::ShiftRight: return KEY_RIGHT_SHIFT;
    case Base::Key::CtrlRight: return KEY_RIGHT_CONTROL;
    case Base::Key::AltLeft: return KEY_LEFT_ALT;
    case Base::Key::Space: return KEY_SPACE;
    case Base::Key::AltRight: return KEY_RIGHT_ALT;
    case Base::Key::Menu: return KEY_KB_MENU;
    case Base::Key::NumLock: return KEY_NUM_LOCK;
    case Base::Key::NumpadDivide: return KEY_KP_DIVIDE;
    case Base::Key::NumpadMultiply: return KEY_KP_MULTIPLY;
    case Base::Key::NumpadMinus: return KEY_KP_SUBTRACT;
    case Base::Key::NumpadPlus: return KEY_KP_ADD;
    case Base::Key::NumpadEqual: return KEY_KP_EQUAL;
    case Base::Key::NumpadEnter: return KEY_KP_ENTER;
    case Base::Key::NumpadDecimal: return KEY_KP_DECIMAL;
    case Base::Key::Numpad1: return KEY_KP_1;
    case Base::Key::Numpad2: return KEY_KP_2;
    case Base::Key::Numpad3: return KEY_KP_3;
    case Base::Key::Numpad4: return KEY_KP_4;
    case Base::Key::Numpad5: return KEY_KP_5;
    case Base::Key::Numpad6: return KEY_KP_6;
    case Base::Key::Numpad7: return KEY_KP_7;
    case Base::Key::Numpad8: return KEY_KP_8;
    case Base::Key::Numpad9: return KEY_KP_9;
    case Base::Key::Numpad0: return KEY_KP_0;
    default: return KEY_NULL;
    }
}