#include <stdlib.h>
#include "raylib.h"

#define WINDOW_TITLE "Cnake - Basic Snake game written in C using Raylib."

typedef enum EBool { NO = 0, YES = 1, FALSE = 0, TRUE = 1 } EBool;
typedef enum EGameScreen { TITLE, GAMEPLAY, ENDING } EGameScreen;

typedef struct SSnake {
    int currentLength;
    EBool isAlive;
} SSnake;

typedef struct SGame {
    EBool isOver;
    EGameScreen screen;
    SSnake snake;
} SGame;

void GameManager(SGame *game)
{
    switch (game->screen) {
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                game->screen = GAMEPLAY;
            }

            if (IsKeyPressed(KEY_ESCAPE))
            {
                CloseWindow();
            }
        } break;

        case GAMEPLAY:
        {
            /* if the game should be over but still in this screen, set to ending */
            if (game->isOver || !game->snake.isAlive)
            {
                game->screen = ENDING;
            }


        } break;

        case ENDING:
        {

        } break;

        default: break;
    }
}

void DrawVisuals(SGame *game)
{
    switch (game->screen) {
        case TITLE:
        {
            DrawText("WELCOME TO CNAKE", 20, 20, 40, DARKGREEN);
            DrawText("A SNAKE GAME WRITTEN IN C USING RAYLIB", 20, 70, 24, DARKGREEN);
            DrawText("PRESS ENTER TO PLAY", 120, 220, 20, DARKGREEN);
        } break;

        case GAMEPLAY:
        {

        } break;

        case ENDING:
        {

        } break;

        default: break;
    }
}

int main(void) {
    const int SCREEN_WIDTH = 700;
    const int SCREEN_HEIGHT = 500;

    /* Setup the window */
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    struct SGame game;
    game.isOver = FALSE;
    game.screen = TITLE;
    game.snake.isAlive = FALSE;
    game.snake.currentLength = 0;

    /* Game loop */
    while (!WindowShouldClose())
    {
        GameManager(&game);

        BeginDrawing();

        ClearBackground(BLACK);
        DrawVisuals(&game);

        EndDrawing();
    }

    /* Destroy the window */
    CloseWindow();

    return 0;
}