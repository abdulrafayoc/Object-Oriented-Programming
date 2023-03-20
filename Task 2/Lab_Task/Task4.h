#pragma once
#include <iostream>

string combineArr(char* c1, char* c2)
{
	int length1 = strlen(c1);
	int length2 = strlen(c2);
	int totalLength = length1 + length2;
	char* result = new char[totalLength + 1];

	for (int i = 0; i < length1; i++)
	{
		result[i] = c1[i];
	}

	for (int i = 0; i < length2; i++)
	{
		result[length1 + i] = c2[i];
	}

	result[totalLength] = '\0';

	return result;
}