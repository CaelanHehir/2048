CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = 2048

LIB_DIR = ./customlib
INCLUDES_DIR = ./includes
UTILS_DIR = ./utils

LIB = $(LIB_DIR)/customlib.a


SOURCES = \
		2048.c									\
		$(UTILS_DIR)/gameloop.c					\
		$(UTILS_DIR)/check_utils.c				\
		$(UTILS_DIR)/move_board_utils.c			\
		$(UTILS_DIR)/merge_board_utils.c		\
		$(UTILS_DIR)/basic_board_utils.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -rf


%.o: %.c $(LIB)
		@$(CC) $(FLAGS) -c $< -o $@


all: $(LIB) $(NAME)

$(LIB):
		@make -C $(LIB_DIR)

$(NAME): $(OBJECTS) $(LIB)
		@$(CC) $(FLAGS) -lncurses -o $(NAME) $(OBJECTS) $(LIB)
		@echo "2048 executable created"

clean:
		@$(RM) $(OBJECTS)
		@make clean -C $(LIB_DIR)
		@echo "Removed .o files"

fclean: clean
		@$(RM) $(NAME)
		@make fclean -C $(LIB_DIR)
		@echo "Removed executable file"

re: fclean all

.PHONY: all clean fclean re
