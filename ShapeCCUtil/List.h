#pragma once
#include <stdlib.h>
#include "ErrorReporter.h"

typedef struct
{
	void** data;
	size_t block_size;
	size_t capacity;
	size_t size;
} ccList;

ccErrorCode ccListInitDefault(ccList* list, size_t block_size);
ccErrorCode ccListInit(ccList* list, size_t initial_capacity, size_t block_size);
void ccListDestroy(ccList* list);
void ccListClear(ccList* list);
ccErrorCode ccListResize(ccList* list, size_t new_capacity);
void ccListSet(ccList* list, size_t pos, void* data);
ccErrorCode ccListAdd(ccList* list, void* data);
void* ccListGet(ccList* list, size_t index);