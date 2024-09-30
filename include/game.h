//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include "snake.h"
#include "food.h"

#ifndef CNAKE_GAME_H
#define CNAKE_GAME_H

typedef enum {
    TITLE, GAMEPLAY, ENDING
} Screen;

typedef struct {
    bool isOver;
    Screen screen;
    int score;
} Game;

void game_init(Game *game);
void game_update(Game *game, Snake *snake, Vector2 *snakePosition, int counterTail, int *frameCounter, Vector2 *offset);
void game_draw(int screenWidth, int screenHeight, int squareSize, Vector2 offset);
void game_restart(Game *game, Snake *snake, Vector2 *offset);

#endif //CNAKE_GAME_H
