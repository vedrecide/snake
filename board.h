#ifndef BOARD_H
#define BOARD_H

#include "snake.h"

#define BOARD_HEIGHT 20
#define BOARD_WIDTH 40

void spawn_food(Snake *s, Position *food);

int check_wall_collision(Snake *s);

void draw_board(Snake *s, Position *food);

#endif