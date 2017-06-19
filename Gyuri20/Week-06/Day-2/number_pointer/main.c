#include <stdio.h>
#include <stdint.h>

void printf_numbers(int from, int to)
{
	for (int i = from; i < to; i++)
		printf("%d\n", i);
}

int main()
{
	printf_numbers(2147483637, 2147483647);
	return 0;
}
