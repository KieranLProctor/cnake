//
// Created by Kieran Proctor on 26/09/2024.
//

#include "../include/game.h"
#include "../include/window.h"

void game_update(Game *game, Snake *snake, Food *food)
{
    Vector2 *snakeHead = &snake->position[0];

    switch (snake->direction) {
        case UP:
            snakeHead->y -= 1;
            break;

        case DOWN:
            snakeHead->y += 1;
            break;

        case LEFT:
            snakeHead->x -= 1;
            break;

        case RIGHT:
            snakeHead->x += 1;
            break;

        default:
            break;
    }

    // apple eaten?
    if (snakeHead->x == food->position.x && snakeHead->y == food->position.y) {
        timer_start(&food->timer, food->timer.span);

        PlaySound(food->eatenSound);

        game->score++;
        snake->length++;
        food->eaten = true;
    }

    // collision happened?
    if (snakeHead->x < 0     ||
            snakeHead->x >= GRID_COLS ||
            snakeHead->y < 0     ||
            snakeHead->y >= GRID_COLS)
    {
        game->screen = ENDING;
        return;
    }

    // self collision?
    for (int i = 1; i < snake->length; i++) {
        if (snakeHead->x == snake->position[i].x && snakeHead->y == snake->position[i].y) {
            game->screen = ENDING;
            return;
        }
    }

    // implementation of the movement of the snake from frame to frame
    for (int i = snake->length - 1; i > 0; i--) {
        snake->position[i] = snake->position[i - 1];
    }

    timer_update(&food->timer);
    snake_draw(snake);
}

void game_draw(int cols, int rows, float cellWidth, float cellHeight)
{
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth,
            cellHeight, LIGHTGRAY);
        }
    }
}

void game_handle_input(Snake *snake)
{
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && snake->direction != UP)
    {
        snake->direction = UP;
    }
    else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && snake->direction != LEFT)
    {
        snake->direction = LEFT;
    }
    else if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && snake->direction != DOWN)
    {
        snake->direction = DOWN;
    }
    else if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && snake->direction != RIGHT)
    {
        snake->direction = RIGHT;
    }
}

void game_restart(Game *game, Snake *snake)
{
    game->screen = GAMEPLAY;
    snake_init(snake);
}