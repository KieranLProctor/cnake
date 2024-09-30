//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "raylib.h"
#include "snake.h"

#ifndef CNAKE_FOOD_H
#define CNAKE_FOOD_H

typedef struct {
    Vector2 position;
    Vector2 size;
    bool eaten;
    Sound eatenSound;
    Color colour;
} Food;

void food_init(Food *food, Snake *snake);
void food_update(Food *food);
void food_draw(Food *food);

#endif //CNAKE_FOOD_H
