#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct Timer {
	double display;
	int running;
	timespec begin;
	timespec end;
} Timer;
Timer *timers;
void timer_init(int n) {
	timers = malloc(sizeof(Timer) * n);
	int i;
	for (i=0;i<n;i++){
		timers[i].running=0;
		timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[i].display = 0.0;
		timers[i].begin = temp;
		timers[i].end = temp;
	}
}

void timer_finalize() {
	free(timers);
}

void timer_start(int idx){
	if (timers[idx].running!=1) {
		timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[idx].begin = temp;
		timers[idx].running = 1;
	} 
}

void timer_stop(int idx) {
	if (timers[idx].running!=0) {
		timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[idx].end = temp;
		timers[idx].running = 0;
		timers[idx].display = getTimeDiff(timers[idx].end, timers[idx].begin);	
	}
}

double getTimeDiff(timespec t1, timespec t2) {
	return (double) ((double)t1.tv_sec-(double)t2.tv_sec + (double) pow(10, -9) * ((double)t1.tv_nsec-(double)t2.tv_nsec));
}



double timer_read(int idx) {
	if(timers[idx].running == 1) {
		timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[idx].display = getTimeDiff(temp, timers[idx].begin);
	}	
	return timers[idx].display;
}

void timer_reset(int idx) {
	timers[idx].running=0;
	timers[idx].display=0;
	timespec tempbegin, tempend;
	clock_gettime(CLOCK_MONOTONIC,&tempbegin);
	clock_gettime(CLOCK_MONOTONIC,&tempend);
	timers[idx].begin = tempbegin;
	timers[idx].end = tempend;

}
