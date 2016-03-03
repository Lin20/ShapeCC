#include <stdio.h>
#include "Engine.h"
#include "List.h"

#if defined(_DEBUG) && defined(_WIN32)
#define DWIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#if !defined(_DEBUG) && defined(_WIN32)
#include <Windows.h>
#define STARTUP int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
#define STARTUP int main(const char* args)
#endif

STARTUP
{
	int code;
	if (code = ccEngineInit())
	{
		printf("Failed to start engine, code %i\n", code);
		return code;
	}
	ccEngineLoop();
	ccEngineCleanup();

#ifdef DWIN32
	//Print out any memory leaks
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
