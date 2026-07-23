#ifndef CUSTOMLIB_H
# define CUSTOMLIB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		custom_tolower(int c);
void	custom_bzero(void *s, size_t n);
void	*custom_calloc(size_t nmemb, size_t size);

#endif
