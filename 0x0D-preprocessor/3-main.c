#include <stdio.h>
#include "3-function_like_macro.h"

int main(void)
{
    int num = -5;
    int absValue = ABS(num);

    printf("The absolute value of %d is %d\n", num, absValue);

    return (0);
}
