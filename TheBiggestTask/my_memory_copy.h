#pragma once
#include <iostream>

void* MyMemoryCopy(void* source, void* recipient, const size_t size)
{
	char* localSource = reinterpret_cast<char*>(source);
	char* localRecipient = reinterpret_cast<char*>(recipient);

	for (size_t i = 0; i < size; ++i)
		localRecipient[i] = localSource[i];

	return reinterpret_cast<void*>(localRecipient);
}