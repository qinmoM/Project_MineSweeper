#include "ButtonText.h"

ButtonText::ButtonText(const Text& text, const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains, const UpdateFunc& update)
    : ButtonBase(position, callback, contains, update), text_(text) { }

bool ButtonText::contains(const Base::Point& pos) const
{
    return contains_(*this, pos);
}

void ButtonText::update(HandleInputSemantic& handle, float delta)
{
    if (update_)
        update_(*this, handle, delta);
}

void ButtonText::render(RendererProxy& renderer)
{
    renderer.drawText(text_);
}