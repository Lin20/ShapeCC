#include "Renderer.h"

int ccRendererInit()
{
	sfVideoMode mode = { 256, 224, 32 };

	ccRendererWindow = sfRenderWindow_create(mode, "ShapeCC", sfResize | sfClose, NULL);
	if (!ccRendererWindow)
		return 1;

	return 0;
}

void ccRendererCleanup()
{
	sfRenderWindow_destroy(ccRendererWindow);
}

void ccRendererRender(float interpolation)
{
	sfRenderWindow_clear(ccRendererWindow, sfBlack);

	sfRenderWindow_display(ccRendererWindow);
}
