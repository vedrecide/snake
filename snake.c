#include <conio.h>
#include "snake.h"

void init_snake(Snake *s) {
    s->body[0] = (Position){ .x = 10, .y = 10 };
    s->length = 1;
    s->direction = RIGHT;
}

void move_snake(Snake *s) {
    for (int i = s->length; i > 0; i--) {
        s->body[i] = s->body[i-1];
    }

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

void grow_snake(Snake *s) {
    if (s->length < MAX_SNAKE_LENGTH) {
        s->body[s->length] = s->body[s->length - 1];
        s->length++;
    }
}

int is_position_on_snake(Snake *s, Position *pos) {
    for (int i = 0; i < s->length - 1; i++) {
        if (s->body[i].x == pos->x && s->body[i].y == pos->y) {
            return 1;
        }
    }

    return 0;
}

int check_food_collision(Snake *s, Position *food) {
    return s->body[0].x == food->x && s->body[0].y == food->y;
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