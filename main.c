#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "board.h"
#include "snake.h"

void game_loop(Snake *s, Position *food) {
    while (1) {
        handle_input(s);
        move_snake(s);

        system("cls");
        draw_board(s, food);

        Sleep(300);
    }
}

int main(void) {
    srand(time(NULL));

    Snake s;
    Position food = { rand() % (BOARD_HEIGHT - 2) + 1, rand() % (BOARD_HEIGHT - 2) + 1};

    init_snake(&s);
    game_loop(&s, &food);
    return 0;
}