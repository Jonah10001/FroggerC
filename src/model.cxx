#include "model.hxx"

using namespace ge211;

Model::Model(int size)
        : Model(size, size)
{ }

Model::Model(int width, int height)
        : board_({width, height})
{
    for (size_t i = 1; i < 5; i++) {
        for (size_t j = 0; j < 12; j++){
            river_positions_[{(int)j, (int)i}] = true;
        }
    }
}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}

void
Model::play_move(Position pos)
{
    if (is_game_over()) {
        throw Client_logic_error("Model::play_move: game over");
    }

    Position new_position = pos;

    for (Position posn : board_.all_positions()) {
        if (new_position == posn) {
            really_play_move(new_position);
        }
    }
}


bool
Model::is_player_alive(){
    for (Position posn : car_positions_){
        if (frog_position_ == posn){
            lives_left_ -= 1;
            return false;
        }
    }
    for (Position posn : river_positions_){
        if (frog_position_ == posn){
            for (Position posns : log_positions_){
                if (frog_position_ != posn){
                    lives_left_ -= 1;
                    return false;
                }
            }
        }
    }
    return true;
}

void
Model::really_play_move(Position posn){
    frog_position_ = posn;
}

