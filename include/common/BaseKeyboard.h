#pragma once

namespace Base
{

enum class Key : char
{
    Unknown = 0,    // NULL
    A,              // a | A
    B,              // b | B
    C,              // c | C
    D,              // d | D
    E,              // e | E
    F,              // f | F
    G,              // g | G
    H,              // h | H
    I,              // i | I
    J,              // j | J
    K,              // k | K
    L,              // l | L
    M,              // m | M
    N,              // n | N
    O,              // o | O
    P,              // p | P
    Q,              // q | Q
    R,              // r | R
    S,              // s | S
    T,              // t | T
    U,              // u | U
    V,              // v | V
    W,              // w | W
    X,              // x | X
    Y,              // y | Y
    Z,              // z | Z
    Num1,           // 1 | !
    Num2,           // 2 | @
    Num3,           // 3 | #
    Num4,           // 4 | $
    Num5,           // 5 | %
    Num6,           // 6 | ^
    Num7,           // 7 | &
    Num8,           // 8 | *
    Num9,           // 9 | )
    Num0,           // 0 | )
    Escape,         // Escape
    Tab,            // Tab
    CapsLock,       // CapsLock
    ShiftLeft,      // leftShift
    CtrlLeft,       // leftControl
    Backspace,      // Backspace
    Enter,          // Enter
    ShiftRight,     // rightShift
    Escape,         // Escape
    CtrlRight,      // rightControl
    AltLeft,        // leftAlt
    Space,          // Space
    AltRight,       // rightAlt
    Menu,           // Menu
    Hyphen,         // - | _
    Equal,          // = | +
    LBracket,       // [ | {
    RBracket,       // ] | }
    Backslash,      // \ | |
    Semicolon,      // ; | :
    Apostrophe,     // ' | "
    Grave,          // ` | ~
    Comma,          // , | <
    Period,         // . | >
    Slash,          // / | ?
    F1,             // F1
    F2,             // F2
    F3,             // F3
    F4,             // F4
    F5,             // F5
    F6,             // F6
    F7,             // F7
    F8,             // F8
    F9,             // F9
    F10,            // F10
    F11,            // F11
    F12,            // F12
    PrintScreen,    // Print Screen
    ScrollLock,     // Scroll Lock
    Pause,          // Pause
    Insert,         // Insert
    Home,           // Home
    PageUp,         // Page Up
    Delete,         // Delete Forward
    End,            // End
    PageDown,       // Page Down
    Right,          // Right
    Left,           // Left
    Down,           // Down
    Up,             // Up
    // Keypad
    NumLock,        // Num Lock
    NumpadDivide,   // /
    NumpadMultiply, // *
    NumpadMinus,    // -
    NumpadPlus,     // +
    NumpadEqual,    // =
    NumpadEnter,    // Enter
    NumpadDecimal,  // . | Delete
    Numpad1,        // 1 | End
    Numpad2,        // 2 | Down Arrow
    Numpad3,        // 3 | Page Down
    Numpad4,        // 4 | Left Arrow
    Numpad5,        // 5
    Numpad6,        // 6 | Right Arrow
    Numpad7,        // 7 | Home
    Numpad8,        // 8 | Up Arrow
    Numpad9,        // 9 | Page Up
    Numpad0         // 0 | Insert
};

}