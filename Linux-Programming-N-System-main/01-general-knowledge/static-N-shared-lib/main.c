#include <stdio.h>
#include "math.h"

int main()
{
    check_version();
    printf("4 + 8 = %d\n", sum(4, 8));
    printf("100 + 1 = %d\n", add(100));
    printf("100 - 1 = %d\n", del(100));

    return 0;
}