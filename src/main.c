#include "raylib.h"
#include "../include/main.h"
#include "../include/window.h"
#include "../include/game.h"

int main(void)
{
//    InitAudioDevice();

    /* setup the window */
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    Game game;
    game_init(&game);
    game.screen = TITLE;

    Snake snake;
    snake_init(&snake);

    Timer foodDelay;
    foodDelay.span = 1.0;
    foodDelay.active = false;

    Food food;
    food_init(&food, &snake, &foodDelay);

    /* game loop */
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        game_draw(GRID_COLS, GRID_ROWS, CELL_WIDTH, CELL_HEIGHT);

        switch (game.screen) {
            case TITLE:
                DrawText("WELCOME TO CNAKE", 20, 20, 40, DARKGREEN);
                DrawText("A SNAKE GAME WRITTEN IN C USING RAYLIB", 20, 70, 24, DARKGREEN);
                DrawText("PRESS ENTER TO PLAY", 120, 220, 20, DARKGREEN);

                if (IsKeyPressed(KEY_ENTER))
                {
                    game.screen = GAMEPLAY;
                }

                break;

            case GAMEPLAY:
                game_handle_input(&snake);
                game_update(&game, &snake, &food);

                break;

            case ENDING:
                DrawText("GAME OVER", 20, 20, 40, DARKGREEN);
                DrawText("A SNAKE GAME WRITTEN IN C USING RAYLIB", 20, 70, 24, DARKGREEN);
                DrawText("PRESS ENTER TO PLAY AGAIN", 120, 220, 20, DARKGREEN);

                if (IsKeyPressed(KEY_ENTER))
                {
                    game_restart(&game, &snake);
                }

                break;

            default: break;
        }

        EndDrawing();
    }

    /* destroy the window */
    CloseWindow();

    return 0;
}