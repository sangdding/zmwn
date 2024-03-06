#include <stdio.h>

#include "file.h"
#include "initializer.h"

int main()
{
    printf("initalize test\n");

    printf("%d\n", initalize_device("/dev/nvme0n2")); 
}