#pragma once

#include "model.hxx"

#include <string>

class View
{
public:
    /// Constructs a view that knows about the given model.
    explicit View(Model const& model);

    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

private:
    Model const& model_;
    ge211::sprites::Rectangle_sprite const frog_sprite_;
    ge211::sprites::Circle_sprite const car_sprite_;
    ge211::sprites::Rectangle_sprite const road_sprite_;
    ge211::sprites::Rectangle_sprite const log_sprite_;
    ge211::sprites::Rectangle_sprite const river_sprite_;
    ge211::sprites::Rectangle_sprite const barrier_sprite_;
    ge211::sprites::Rectangle_sprite const end_sprite_;
};
