//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "../include/game.h"
#include "../include/window.h"

void game_init(Game *game)
{
    game->isOver = false;
    game->screen = TITLE;
    game->score = 0;
}

void game_update(Game *game, Snake *snake, Vector2 *snakePosition, int counterTail, int *frameCounter, Vector2 *offset)
{
    /* player movement */
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (snake[0].direction.y == 0))
    {
        snake[0].direction = (Vector2){ 0, -SQUARE_SIZE };
    }
    else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && (snake[0].direction.x == 0))
    {
        snake[0].direction = (Vector2){ -SQUARE_SIZE, 0 };
    }
    else if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && (snake[0].direction.y == 0))
    {
        snake[0].direction = (Vector2){ 0, SQUARE_SIZE };
    }
    else if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && (snake[0].direction.x == 0))
    {
        snake[0].direction = (Vector2){ SQUARE_SIZE, 0 };
    }

    for (int i = 0; i < counterTail; i++)
    {
        snakePosition[i] = snake[i].position;
    }

    /* snake speed */
    if ((*frameCounter%2000) == 0)
    {
        for (int i = 0; i < counterTail; i++)
        {
            if (i == 0)
            {
                snake[0].position.x += snake[0].direction.x;
                snake[0].position.y += snake[0].direction.y;
            }
            else {
                snake[i].position = snakePosition[i - 1];
            }
        }
    }

    if (((snake[0].position.x) > (WINDOW_WIDTH - offset->x)) ||
        ((snake[0].position.y) > (WINDOW_HEIGHT - offset->y)) ||
        (snake[0].position.x < 0) || (snake[0].position.y < 0))
    {
        game->isOver = true;
        game->screen = ENDING;
    }

    (*frameCounter)++;
}

void game_draw(int screenWidth, int screenHeight)
{
    for (int i = 0; i < GRID_COLS + 1; i++)
    {
        DrawLineV((Vector2){((screenWidth - BORDER_OFFSET * 2) / GRID_COLS * i) + BORDER_OFFSET, BORDER_OFFSET}, (Vector2){((screenWidth - BORDER_OFFSET * 2) / GRID_COLS * i) + BORDER_OFFSET, (screenHeight - BORDER_OFFSET)}, LIGHTGRAY);
    }

    for (int i = 0; i < GRID_ROWS + 1; i++)
    {
        DrawLineV((Vector2){BORDER_OFFSET, ((screenHeight - BORDER_OFFSET * 2) / GRID_ROWS * i) + BORDER_OFFSET}, (Vector2){screenWidth - BORDER_OFFSET, ((screenHeight - BORDER_OFFSET * 2) / GRID_ROWS * i) + BORDER_OFFSET}, LIGHTGRAY);
    }
}

void game_restart(Game *game, Snake *snake, Vector2 *offset)
{
    game->screen = GAMEPLAY;
    snake_init(snake, offset);
}