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
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (snake[0].speed.y == 0))
    {
        snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
    }
    else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && (snake[0].speed.x == 0))
    {
        snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
    }
    else if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && (snake[0].speed.y == 0))
    {
        snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
    }
    else if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && (snake[0].speed.x == 0))
    {
        snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
    }

    for (int i = 0; i < counterTail; i++)
    {
        snakePosition[i] = snake[i].position;
    }

    if ((*frameCounter%5) == 0)
    {
        for (int i = 0; i < counterTail; i++)
        {
            if (i == 0)
            {
                snake[0].position.x += snake[0].speed.x;
                snake[0].position.y += snake[0].speed.y;
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

void game_draw(int screenWidth, int screenHeight, int squareSize, Vector2 offset)
{
    // Draw grid lines
    for (int i = 0; i < screenWidth/squareSize + 1; i++)
    {
        DrawLineV((Vector2){squareSize*i + offset.x/2, offset.y/2}, (Vector2){squareSize*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
    }

    for (int i = 0; i < screenHeight/squareSize + 1; i++)
    {
        DrawLineV((Vector2){offset.x/2, squareSize*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, squareSize*i + offset.y/2}, LIGHTGRAY);
    }
}

void game_restart(Game *game, Snake *snake, Vector2 *offset)
{
    game->screen = GAMEPLAY;
    snake_init(snake, offset);
}