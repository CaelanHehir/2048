#include "customlib.h"

int	custom_tolower(int c)
{
	if ((c >= 65 && c <= 90))
		c += 32;
	return (c);
}

/* #include <stdio.h>

int	main(int argc, char *argv[])
{
	char	c;

	if (!(argc > 1))
		return (0);
	c = argv[1][0];
	printf("Input: %c\nOutput: %c\n", c, custom_tolower(c));
} */
