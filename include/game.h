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
void game_update(Game *game, Snake *snake, Food *food);
void game_draw(int cols, int rows, float cellWidth, float cellHeight);
void game_handle_input(Snake *snake);
void game_restart(Game *game, Snake *snake);

#endif //CNAKE_GAME_H
