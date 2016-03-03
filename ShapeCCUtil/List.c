#include "List.h"

#define INIT_CAPACITY 8

ccErrorCode ccListInitDefault(ccList* list, size_t block_size)
{
	return ccListInit(list, INIT_CAPACITY, block_size);
}

ccErrorCode ccListInit(ccList* list, size_t initial_capacity, size_t block_size)
{
	list->block_size = block_size;
	list->size = 0;
	list->capacity = initial_capacity;
	list->data = malloc(block_size * initial_capacity);
	if (!list->data)
	{
		ccError("Failed to init list memory");
		return ccBACKEND;
	}

	return ccOK;
}

void ccListDestroy(ccList* list)
{
	free(list->data);
}

void ccListClear(ccList* list)
{
	list->size = 0;
}

ccErrorCode ccListResize(ccList* list, size_t new_capacity)
{
	void* new_pointer = realloc(list->data, list->block_size * new_capacity);
	if (new_pointer == NULL)
	{
		ccError("Failed to resize list");
		return ccBACKEND;
	}
	list->data = new_pointer;
	list->capacity = new_capacity;
	return ccOK;
}

void ccListSet(ccList* list, size_t pos, void* data)
{
	if (pos > list->size)
		return;

	list->data[pos] = data;
}

ccErrorCode ccListAdd(ccList* list, void* data)
{
	if (list->size == list->capacity)
	{
		if (ccListResize(list, list->capacity * 2))
		{
			return ccBACKEND;
		}
	}
	list->data[list->size++] = data;
	return ccOK;
}

void* ccListGet(ccList* list, size_t index)
{
	if (index >= list->size)
	{
		ccError("Index outside container size");
		return NULL;
	}
	return list->data[index];
}

