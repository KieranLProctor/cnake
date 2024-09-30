#include "raylib.h"
#include "../include/main.h"
#include "../include/window.h"
#include "../include/game.h"

static Game g_game = { 0 };
static Snake g_snake[SNAKE_SIZE] = { 0 };
static Vector2 g_snakePosition[SNAKE_SIZE] = { 0 };
static Vector2 g_offset = { 0 };
static bool g_isDebugging = false;
static int g_counterTail = 0;
static int g_frameCounter = 0;

void debug(Game *game, Snake *snake)
{
    DrawText(TextFormat("GAME OVER?: %i", game->isOver), 20, 20, 18, DARKGREEN);

    DrawText(TextFormat("SNAKE HEAD X: %f", snake[0].position.x), 20, 60, 18, DARKGREEN);
    DrawText(TextFormat("SNAKE HEAD Y: %f", snake[0].position.y), 20, 80, 18, DARKGREEN);
    DrawText(TextFormat("SNAKE LENGTH: %i", snake->size.x), 20, 100, 18, DARKGREEN);
}

void init(void)
{
    g_offset.x = WINDOW_WIDTH%SQUARE_SIZE;
    g_offset.y = WINDOW_HEIGHT%SQUARE_SIZE;
    g_counterTail = 1;
    g_frameCounter = 0;

    game_init(&g_game);
    snake_init(g_snake, &g_offset);

    for (int i = 0; i < SNAKE_SIZE; i++)
    {
        g_snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }
}

int main(void)
{
//    InitAudioDevice();

    /* setup the window */
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    init();

    /* game loop */
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        switch (g_game.screen)
        {
            case TITLE:
                DrawText("WELCOME TO CNAKE", 20, 20, 40, DARKGREEN);
                DrawText("A SNAKE GAME WRITTEN IN C USING RAYLIB", 20, 70, 24, DARKGREEN);
                DrawText("PRESS ENTER TO PLAY", 120, 220, 20, DARKGREEN);

                if (IsKeyPressed(KEY_ENTER))
                {
                    g_game.screen = GAMEPLAY;
                }

                break;

            case GAMEPLAY:
                game_update(&g_game, g_snake, g_snakePosition, g_counterTail, &g_frameCounter, &g_offset);
                game_draw(WINDOW_WIDTH, WINDOW_HEIGHT, SQUARE_SIZE, g_offset);
                snake_draw(g_snake, g_counterTail);

                break;

            case ENDING:
                DrawText("GAME OVER", 20, 20, 40, DARKGREEN);
                DrawText(TextFormat("YOUR SCORE: %i", g_game.score), 20, 70, 24, DARKGREEN);
                DrawText("PRESS ENTER TO PLAY AGAIN", 120, 220, 20, DARKGREEN);

                if (IsKeyPressed(KEY_ENTER))
                {
                    game_restart(&g_game, g_snake, &g_offset);
                }

                break;

            default: break;
        }

        if (IsKeyPressed(KEY_I))
        {
            g_isDebugging = !g_isDebugging;
        }

        if (g_isDebugging)
        {
            debug(&g_game, g_snake);
        }

        EndDrawing();
    }

    /* destroy the window */
    CloseWindow();

    return 0;
}