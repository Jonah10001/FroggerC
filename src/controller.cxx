#include "controller.hxx"

Controller::Controller(int size)
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set );
}
