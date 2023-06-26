#include <stdio.h>
#include "main.h"

int main(void)
{
    int a = 10;
    int b = 20;

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap_integers(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}
