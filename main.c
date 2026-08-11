#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "board.h"
#include "snake.h"

void game_loop(Snake *s) {
    while (1) {
        handle_input(s);
        move_snake(s);

        system("cls");
        draw_board(s);

        Sleep(300);
    }
}

int main(void) {
    Snake s;

    init_snake(&s);
    game_loop(&s);
    return 0;
}