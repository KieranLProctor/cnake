//
// Created by Kieran Proctor on 26/09/2024.
//

#include "../include/food.h"
#include "../include/window.h"

void food_init(Food *food, Snake *snake, Timer *timer)
{
    food->timer = *timer;

    do {
        food->position.x = GetRandomValue(0, GRID_COLS - 1);
        food->position.y = GetRandomValue(0, GRID_ROWS - 1);

        bool validPosition = true;

        for (int i = 0; i < snake->length; i++) {
            if (food->position.x == snake->position[i].x && food->position.y == snake->position[i].y) {
                validPosition = false;
                break;
            }
        }

        if (validPosition) {
            break;
        }

    } while (true);
}

void food_update(Food *food)
{

}