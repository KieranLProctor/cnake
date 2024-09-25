//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "types.h"
#include "raylib.h"

#ifndef CNAKE_SNAKE_H
#define CNAKE_SNAKE_H

typedef struct {
    int length;
    bool isAlive;
    Direction direction;
    Vector2 position[200];
} Snake;

void snake_init(Snake *snake);
//void snake_update(Snake *snake);
void snake_draw(Snake *snake);

#endif //CNAKE_SNAKE_H
