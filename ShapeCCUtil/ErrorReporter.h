#pragma once

#include <stdio.h>

typedef enum
{
	ccOK = 0,
	ccBACKEND = 1,
	ccINTERNAL = 2
} ccErrorCode;

inline void ccError(const char* message)
{
	printf("**Error**\n%s(%i): %s\n", __FILE__, __LINE__, message);
}