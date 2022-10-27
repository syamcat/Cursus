#include <stdio.h>
#include <stdint.h>

int main(void)
{
	// double	decimal;
	// double	interger;
	int16_t	decimal;
	int16_t	interger;

	decimal = -0xF;
	interger = -0xF;

	printf("decimal: %d\n", decimal);
	printf("interger: %i\n", interger);

	return 0;
}
