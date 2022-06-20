#pragma once
#include <iostream>
using namespace std;

static clock_t s_prevTick;
static float s_deltaTime;
static float s_fixedTime;

class Timer
{
public:
	float GetDT(void)
	{
		clock_t currentTick = clock();
		float deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;

		s_deltaTime = deltaTime;
		s_prevTick = currentTick;

		return s_deltaTime;
	}
private:

};