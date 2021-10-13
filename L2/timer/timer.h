#ifndef TIMER_H
#define TIMER_H

typedef struct timespec timespec; 
void timer_init(int n);
double getTimeDiff(timespec t1, timespec t2);
void timer_finalize();

void timer_start(int idx);

void timer_stop(int idx);

double timer_read(int idx);

void timer_reset(int idx);

#endif
