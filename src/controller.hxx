#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller(int);

protected:
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;
    bool key_up;
    bool key_back;
    bool key_left;
    bool key_right;
};
