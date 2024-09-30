//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "types.h"
#include "raylib.h"

#ifndef CNAKE_SNAKE_H
#define CNAKE_SNAKE_H

typedef struct {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color colour;
} Snake;

void snake_init(Snake *snake, Vector2 *offset);
//void snake_update(Snake *snake);
void snake_draw(Snake *snake, int counterTail);

#endif //CNAKE_SNAKE_H
