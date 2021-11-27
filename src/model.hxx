#pragma once

#include "board.hxx"

#include <ge211.hxx>

#include <position_set.hxx>
#include <iostream>
#include <vector>

class Model
{
public:
    using Dimensions = Board::Dimensions;

    using Position = Board::Position;

    using Rectangle = Board::Rectangle;

    explicit Model(int size = 12);

    Model(int width, int height);

    Rectangle board() const;

    bool is_game_over() const
    {
        return lives_left() == 0;
    }

    int lives_left() const{
        return lives_left_;
    }

    Position frog_position() const{
        return frog_position_;
    }

    Position_set car_positions() const{
        return car_positions_;
    }

    Position_set log_positions() const{
        return log_positions_;
    }

    Position_set river_positions() const{
        return river_positions_;
    }

    void play_move(Position);


private:

    int lives_left_ = 3;
    Position frog_position_ = {6, 11};
    Position_set car_positions_ = {{1, 10}, {3, 10}, {6, 9}, {8 , 9}, {9,
                                                                         8},
                                   {10, 8}, {3, 7}, {4 , 6}, {7 , 6}};
    Position_set river_positions_;
    Position_set log_positions_ = {{1, 1}, {1, 2}, {1, 3}, {2, 2}, {2, 3},
                                    {2, 4}, {3, 5}, {3, 6}, {3, 7}, {4, 9},
                                    {4, 10}, {4, 11}};
    Board board_;

    bool is_player_alive();

    void really_play_move(Position);
};
