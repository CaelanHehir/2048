/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:35:31 by chehir            #+#    #+#             */
/*   Updated: 2026/07/23 16:09:47 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/2048.h"

int	main(void)
{
	WINDOW	*window;
	int		*board;
	char	input;
	int		replay;
	int		result;

	window = newwin(100, 35, 0, 0);

	setup();

	replay = 1;
	while (replay)
	{
		board = init_board();
		result = gameloop(board);
		display_board(board);
		if (result)
			mvprintw(11, 0, "Congratulations! You win! :)");
		else
			mvprintw(11, 0, "Oh nooooooo! You lost :(");
		mvprintw(13, 0, "Would you like to play again? (y/n)");
		input = '\0';
		while (input != 'y' && input != 'n')
		{
			input = getch();
		}
		if (input == 'n')
			replay = 0;
		free(board);
	}
	endwin();
	return (1);
}
