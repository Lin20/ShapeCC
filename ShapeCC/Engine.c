#include "Engine.h"
#include <stdio.h>

#define MAX_FRAMESKIP 8
#define UPDATES_PER_SECOND 60
#define SKIP_TICKS 1000 / UPDATES_PER_SECOND

int ccEngineInit()
{
	int code;
	code = ccRendererInit();
	if (code)
		return code;

	ccEngineClock = sfClock_create();

	return 0;

}

void ccEngineCleanup()
{
	ccRendererCleanup();
	sfClock_destroy(ccEngineClock);
}

void ccEngineLoop()
{
	sfEvent event;
	int update_count = 0;
	float interpolation = 0;
	int frame_count = 0;
	int start = ccEngineTime();
	int next_tick = start;
	int elapsed;

	while (sfRenderWindow_isOpen(ccRendererWindow))
	{
		while (sfRenderWindow_pollEvent(ccRendererWindow, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(ccRendererWindow);
		}

		update_count = 0;
		while (ccEngineTime() > next_tick && update_count < MAX_FRAMESKIP)
		{
			ccEngineUpdate();
			next_tick += SKIP_TICKS;
			update_count++;
		}

		interpolation = (float)(ccEngineTime() + SKIP_TICKS - next_tick) / (float)SKIP_TICKS;
		ccRendererRender(interpolation);
		frame_count++;
		elapsed = ccEngineTime() - start;
		if (elapsed >= 1000)
		{
			frame_count = 0;
			start = ccEngineTime();
		}
	}
}

void ccEngineUpdate()
{

}
