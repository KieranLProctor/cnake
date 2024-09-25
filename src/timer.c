//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>
#include <raylib.h>
#include "../include/timer.h"

void timer_start(Timer *timer, double span)
{
    timer->span = span;
    timer->active = true;
}

void timer_update(Timer *timer)
{
    if (timer->active && timer->span > 0) {
        timer->span -= GetFrameTime();
    }
}

void timer_end(Timer *timer)
{
    timer->active = false;
}

bool timer_done(Timer *timer)
{
    return timer->span <= 0;
}
