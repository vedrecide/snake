#include <stdio.h>
#include <stdlib.h>

#include "board.h"

void spawn_food(Snake *s, Position *food) {
    do {
        food->x = rand() % (BOARD_WIDTH - 2) + 1;
        food->y = rand() % (BOARD_HEIGHT - 2) + 1;
    } while (is_position_on_snake(s, food));
}

int check_wall_collision(Snake *s) {
    return !(s->body[0].x <= 0 ||
           s->body[0].x >= BOARD_WIDTH - 1 ||
           s->body[0].y <= 0 ||
           s->body[0].y >= BOARD_HEIGHT - 1);
}

void draw_board(Snake *s, Position *food) {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int column = 0; column < BOARD_WIDTH; column++) {
            if (row == 0 || row == BOARD_HEIGHT - 1 || column == 0 || column == BOARD_WIDTH - 1) {
                printf("#");
            } else {
                int part = -1;

                for (int i = 0; i < s->length; i++) {
                    if (row == s->body[i].y && column == s->body[i].x) {
                        part = i;
                        break;
                    }
                }

                if (part == 0) {
                    printf("O");
                } else if (part > 0) {
                    printf("o");
                } else if (row == food->y && column == food->x) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}