#pragma once

namespace Base
{

enum class MouseCursor : char
{
    Arrow = 0,          // arrow | default
    Text,               // text | I-beam
    Hand,               // hand
    Cross,              // cross
    ResizeVertical,     // vertical resize
    ResizeHorizontal,   // horizontal resize
    ResizeAll,          // diagonal resize
    RsizeTopLeft,       // top-left bottom-right diagonal resize
    RsizeTopRight,      // top-right bottom-left diagonal resize
    NotAllowed          // not allowed
};

}