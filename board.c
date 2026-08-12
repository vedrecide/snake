#include <stdio.h>
#include <stdlib.h>

#include "board.h"

void spawn_food(Snake *s, Position *food) {
    do {
        food->x = rand() % (BOARD_WIDTH - 2) + 1;
        food->y = rand() % (BOARD_HEIGHT - 2) + 1;
    } while (is_position_on_snake(s, food));
}

void draw_board(Snake *s, Position *food) {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int column = 0; column < BOARD_WIDTH; column++) {
            if (row == 0 || row == BOARD_HEIGHT - 1 || column == 0 || column == BOARD_WIDTH - 1) {
                printf("#");
            } else if (row == s->body[0].y && column == s->body[0].x) {
                printf("O");
            } else if (row == food->y && column == food->x) {
                printf("*");
            } else if (check_food_collision(s, food)) {
                spawn_food(s, food);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}