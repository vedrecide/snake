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

        if (check_food_collision(s, food)) {
            if (s->length < MAX_SNAKE_LENGTH) {
                grow_snake(s);
                spawn_food(s, food);
            }
        }

        system("cls");
        draw_board(s, food);

        if (check_wall_collision(s) || check_self_collision(s)) {
            break;
        }

        Sleep(100);
    }
}

int main(void) {
    srand(time(NULL));

    Snake s;
    Position food = { rand() % (BOARD_WIDTH - 2) + 1, rand() % (BOARD_HEIGHT - 2) + 1};

    init_snake(&s);
    game_loop(&s, &food);
    return 0;
}