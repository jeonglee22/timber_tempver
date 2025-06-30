#include "stdafx.h"

int main()
{
    FRAMEWORK.Init(1366, 768, "Timber!");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}