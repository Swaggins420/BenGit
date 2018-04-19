//GameTimer.h
/*#pragma once
#include <time.h>



class GameTimer {
public:
	GameTimer();
	~GameTimer();

	clock_t startTime = time(0);
	float lastFrameTime();

	time_t timeDiff(time_t time1, time_t time2);

	clock_t clockDiff(clock_t time1, clock_t time2);

};
*/







//GameTimer.cpp
/*#include "GameTimer.h"

GameTimer::GameTimer()
{

}

GameTimer::~GameTimer() {}

float GameTimer::lastFrameTime()
{

	clock_t tickCount = clock();//CPU "ticks" since the program started.


	float msMult = 1000.0f / CLOCKS_PER_SEC;//Conversion rate between ticks and millaseconds.


	float ms = (tickCount * msMult);//Convert from ticks to seconds.

	return ms;
}


time_t GameTimer::timeDiff(time_t time1, time_t time2)
{
	return time1 - time2;
}

clock_t GameTimer::clockDiff(clock_t time1, clock_t time2)
{
	return time1 - time2;
}*/