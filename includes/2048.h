#ifndef TWENTY_FOURTY_EIGHT_H
# define TWENTY_FOURTY_EIGHT_H

# include "../customlib/customlib.h"
# include <ncurses.h>
# include <time.h>

void    setup();
int	    *init_board();
void	display_board(int *board);
int 	add_number(int *board);

int 	check_board_full(int *board);
int 	check_possible_moves(int *board);
void	check_merge(int *board);
int     check_win(int *board);

int	    move_up(int *board, int index);
int 	move_down(int *board, int index);
int 	move_left(int *board, int index);
int	    move_right(int *board, int index);
int	    move_board(int *board, char direction);

int	    merge_up(int *board, int index);
int	       merge_down(int *board, int index);
int	    merge_left(int *board, int index);
int	    merge_right(int *board, int index);
int	    merge_board(int *board, char direction);

char	get_user_input();
int	    gameloop(int *board);

#endif