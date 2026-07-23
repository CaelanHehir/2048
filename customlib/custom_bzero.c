#include "customlib.h"

void	custom_bzero(void *s, size_t n)
{
	char	*cast;

	cast = s;
	while (n--)
		*cast++ = '\0';
}

/* #include <stdio.h>

 int	main()
{
	char *str = "Hello";
	printf("%s\n", str);
	custom_bzero(&str, 5);
	printf("%s\n", str);
} */
