//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "raylib.h"
#include "timer.h"
#include "snake.h"

#ifndef CNAKE_FOOD_H
#define CNAKE_FOOD_H

#define FOOD_SPAWN_DELAY 1.0

typedef struct {
    Vector2 position;
    Sound eatenSound;
    bool eaten;
    bool firstRender;
    Timer timer;
} Food;

void food_init(Food *food, Snake *snake, Timer *timer);
void food_update(Food *food);
void food_draw(Food *food);

#endif //CNAKE_FOOD_H
