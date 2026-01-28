#pragma once

#include "ButtonBase.h"
#include "Text.h"

class ButtonText : public ButtonBase
{
public:
    virtual bool contains(const Base::Point& pos) const override;
    virtual Text& getText() { return text_; }
    virtual const Text& getText() const { return text_; }

    virtual void update(HandleInputSemantic& handle, float delta) override;
    virtual void render(RendererProxy& renderer) override;
public:
    ButtonText(const Text& text, const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains, const UpdateFunc& update);
protected:
    Text text_;
};