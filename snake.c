#include <conio.h>
#include "snake.h"

void init_snake(Snake *s) {
    s->body[0] = (Position){ .x = 10, .y = 10 };
    s->length = 1;
    s->direction = RIGHT;
}

void move_snake(Snake *s) {
    switch(s->direction) {
        case UP:
            s->body[0].y--;
            break;
        case DOWN:
            s->body[0].y++;
            break;
        case LEFT:
            s->body[0].x--;
            break;
        case RIGHT:
            s->body[0].x++;
            break;
    }
}

void handle_input(Snake *s) {
    if (_kbhit()) {
        char key = _getch();

        switch (key) {
            case 'w':
                s->direction = UP;
                break;
            case 's':
                s->direction = DOWN;
                break;
            case 'a':
                s->direction = LEFT;
                break;
            case 'd':
                s->direction = RIGHT;
        }
    }
}