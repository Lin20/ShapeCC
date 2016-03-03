#pragma once

#include <SFML\Graphics.h>

sfRenderWindow* ccRendererWindow;

int ccRendererInit();
void ccRendererCleanup();
void ccRendererRender(float interpolation);