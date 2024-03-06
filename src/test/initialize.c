#include <stdio.h>

#include "file.h"
#include "initializer.h"

int main()
{
    printf("initalize test\n");

    printf("%d\n", initalize_device("/dev/nvme0n2")); 

    printf("init metadata\n");

    printf("%d\n", init_metadata());   
}