#include "customlib.h"

void	*custom_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	custom_bzero(ptr, nmemb * size);
	return (ptr);
}

/*#include <stdio.h>

int     main()
{
	char	*str = custom_calloc(5, sizeof(char));
	int i = 0;

	while (i < 5)
	{
		printf("Elem: %d\n", str[i]);
		i++;
	}
	free(str);
}*/
