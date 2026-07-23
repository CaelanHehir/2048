/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:06:54 by chehir            #+#    #+#             */
/*   Updated: 2026/07/23 15:46:50 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/2048.h"

char	get_user_input()
{
	char	c;
	int		valid;

	valid = 0;
	while (!valid)
	{
		c = getch();
		c = custom_tolower(c);
		if (c == 'w' || c == 'a' || c == 's' || c == 'd')
			valid = 1;
	}
	return (c);
}

int	gameloop(int *board)
{
	int	loop;
	int	input;
	int	moved;

	loop = 1;
	while (loop)
	{
		moved = 0;
		display_board(board);
		mvprintw(11, 0, "");
		input = get_user_input();
		mvprintw(11, 12, "%c\n", input);
		moved += merge_board(board, input);
		moved += move_board(board, input);
		check_merge(board);
		if (check_win(board))
			return (1);
		if (moved)
			add_number(board);
		if (!check_possible_moves(board))
			loop = 0;
	}
	return (0);
}
