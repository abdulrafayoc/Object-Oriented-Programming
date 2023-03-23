#pragma once

bool sameChar(char* c1, char* c2)
{
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0')
    {
        if (c1[i] != c2[i])
            return false;
        i++;
    }
    return true;
}