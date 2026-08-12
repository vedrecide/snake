#include <stdio.h>
#include <stdlib.h>

#include "board.h"

void draw_board(Snake *s, Position *food) {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int column = 0; column < BOARD_WIDTH; column++) {
            if (row == 0 || row == BOARD_HEIGHT - 1 || column == 0 || column == BOARD_WIDTH - 1) {
                printf("#");
            } else if (row == s->body[0].y && column == s->body[0].x) {
                printf("O");
            } else if (row == food->y && column == food->x) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}