#include <unistd.h>

void print_alphabet_x10(void) 
{
    int i, j;

    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 26; j++) 
	{
            putchar('a' + j);
        }
        putchar('\n');
    }
}
