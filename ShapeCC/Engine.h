#pragma once

#include "Renderer.h"

sfClock* ccEngineClock;

int ccEngineInit();
void ccEngineCleanup();
void ccEngineLoop();
void ccEngineUpdate();

inline int ccEngineTime()
{
	return sfTime_asMilliseconds(sfClock_getElapsedTime(ccEngineClock));
}