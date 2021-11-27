#include "view.hxx"

using Sprite_set = ge211::Sprite_set;
using Color = ge211::Color;

static int const grid_size = 80;

View::View(Model const& model)
        : model_(model),
          frog_sprite_({(int)(grid_size * .75), (int)(grid_size * .75)},
                       Color::medium_green()),
          car_sprite_(grid_size * .46, Color::black()),
          road_sprite_({(int)(grid_size * 12), (int)(grid_size * 4)},
                       Color::from_rgba(130, 130, 130, 1.0)),
          log_sprite_({(int)(grid_size * 2), (int)(grid_size)},
                      Color::from_rgba(165, 42, 42, 1.0)),
          river_sprite_({(int)(grid_size * 12), (int)(grid_size * 4)},
                        Color::medium_cyan()),
          barrier_sprite_({(int)(grid_size * 12), (int)(grid_size)},
                          Color::medium_yellow()),
          end_sprite_({(int)(grid_size * 12), (int)(grid_size)},
                      Color::medium_yellow())


{ }

void
View::draw(ge211::Sprite_set& set)
{
    for (size_t i = 0; i < 12; i++){
        if (i == 0){
            set.add_sprite(end_sprite_, {0, 0})
        }
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return grid_size * model_.board().dimensions();
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Reversi";
}
