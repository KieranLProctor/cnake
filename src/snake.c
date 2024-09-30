//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "../include/snake.h"
#include "../include/window.h"

void snake_init(Snake *snake, Vector2 *offset)
{
    for (int i = 0; i < SNAKE_SIZE; i++)
    {
        snake[i].position = (Vector2){ offset->x/2, offset->y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

        if (i == 0)
        {
            snake[i].colour = DARKGREEN;
        }
        else
        {
            snake[i].colour = LIME;
        }
    }
}

void snake_draw(Snake *snake, int counterTail)
{
    for (int i = 0; i < counterTail; i++)
    {
        DrawRectangleV(snake[i].position, snake[i].size, snake[i].colour);
    }
}
