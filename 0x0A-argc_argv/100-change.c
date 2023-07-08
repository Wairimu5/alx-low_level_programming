#include <stdio.h>
#include <stdlib.h>

int get_coin_count(int cents, int coin_value)
{
	int coin_count = cents / coin_value;
	return (coin_count);
}

int calculate_change(int cents)
{
	int coin_count = 0;
	int coin_value[] = {25, 10, 5, 2, 1};
	int i, num_coins;

	for (i = 0; i < 5; i++)
	{
		num_coins = get_coin_count(cents, coin_value[i]);
		coin_count += num_coins;
		cents -= num_coins * coin_value[i];
	}

	return (coin_count);
}

int main(int argc, char *argv[])
{
	int cents, coin_count;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	coin_count = calculate_change(cents);

	printf("%d\n", coin_count);

	return (0);
}
