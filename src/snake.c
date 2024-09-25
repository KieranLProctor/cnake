//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "../include/snake.h"
#include "../include/window.h"

void snake_init(Snake *snake)
{
    snake->length = 1;
    snake->isAlive = true;
    snake->direction = (Direction) GetRandomValue(1, 4);
    snake->position[0].x = GetRandomValue(0, GRID_COLS);
    snake->position[0].y = GetRandomValue(0, GRID_ROWS);
}

void snake_draw(Snake *snake)
{
    Vector2 *head = &snake->position[0];
    Color snakeColour = LIME;
    Color headColour  = DARKGREEN;

    // draw body
    for (int i = 1; i < snake->length; i++) {
        DrawRectangle(snake->position[i].x * CELL_WIDTH, snake->position[i].y * CELL_HEIGHT,
                      CELL_WIDTH, CELL_HEIGHT, snakeColour);
    }

    // draw head
    DrawRectangle(head->x * CELL_WIDTH, head->y * CELL_HEIGHT, CELL_WIDTH,
                  CELL_HEIGHT, headColour);
}
