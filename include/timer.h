//
// Created by Kieran Proctor on 26/09/2024.
//

#include <stdbool.h>

#ifndef CNAKE_TIMER_H
#define CNAKE_TIMER_H

typedef struct {
    double span;
    bool active;
} Timer;

void timer_start(Timer *timer, double span);
void timer_update(Timer *timer);
void timer_end(Timer *timer);
bool timer_done(Timer *timer);

#endif //CNAKE_TIMER_H
