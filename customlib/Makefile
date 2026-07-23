# Use 'nm libft.a' to check functions contained in the libft library

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = customlib.a

SOURCES = custom_bzero.c custom_calloc.c custom_tolower.c

OBJECTS = $(SOURCES:.c=.o)


%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
