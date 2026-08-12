#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 100

typedef struct {
    int x, y;
} Position;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    Position body[MAX_SNAKE_LENGTH];
    int length;
    Direction direction;
} Snake;

void init_snake(Snake *s);

void move_snake(Snake *s);

int is_position_on_snake(Snake *s, Position *pos);

int check_food_collision(Snake *s, Position *food);

void handle_input(Snake *s);

#endif