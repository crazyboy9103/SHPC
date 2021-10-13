#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct Timer {
	int running;
	struct timespec begin;
	struct timespec end;
} Timer;
Timer *timers;
void timer_init(int n) {

	printf("|timer_init|");	
	timers = malloc(sizeof(Timer) * n);
	int i;
	for (i=0;i<n;i++){
		timers[i].running=0;
		struct timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[i].begin = temp;
		timers[i].end = temp;
	}
}

void timer_finalize() {
	printf("|timer_finalize|");	
	free(timers);
}

void timer_start(int idx){
	printf("|timer_start|");	
	if (timers[idx].running!=1) {
		struct timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[idx].begin = temp;
		timers[idx].running = 1;
	} 
	return;
}

void timer_stop(int idx) {
	printf("|timer_stop|");	
	if (timers[idx].running!=0) {
		struct timespec temp;
		clock_gettime(CLOCK_MONOTONIC, &temp);
		timers[idx].end = temp;
		timers[idx].running = 0;
	}
	return;
}

double timer_read(int idx) {
	double time;
	if(timers[idx].running == 0) {
		time = timers[idx].end.tv_sec-timers[idx].begin.tv_sec + pow(10,-9) *(timers[idx].end.tv_nsec-timers[idx].begin.tv_nsec);	
	} else if (timers[idx].running == 1) {
		struct timespec tempCurr;
		clock_gettime(CLOCK_MONOTONIC, &tempCurr);
		time =  tempCurr.tv_sec-timers[idx].begin.tv_sec + pow(10, -9) * (tempCurr.tv_nsec-timers[idx].begin.tv_nsec);	
	}	
	printf("%lf", time);
	return time;
}

void timer_reset(int idx) {
	printf("|timer_reset|");
	timers[idx].running=0;
	struct timespec tempbegin, tempend;
	clock_gettime(CLOCK_MONOTONIC,&tempbegin);
	clock_gettime(CLOCK_MONOTONIC,&tempend);
	timers[idx].begin = tempbegin;
	timers[idx].end = tempend;

}
