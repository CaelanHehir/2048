/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_board_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:01:54 by chehir            #+#    #+#             */
/*   Updated: 2026/07/23 15:46:35 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/2048.h"

void	setup()
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);

	srand(time(NULL));
}

int	*init_board()
{
	int	*board;
	int	i;

	board = custom_calloc(16, sizeof(int));
	i = 0;
	while (i < 16)
		board[i++] = 0;
	add_number(board);
	add_number(board);
	return (board);
}

void	display_board(int *board)
{
	int	line;
	int	column;
	int	i;

	clear();
	i = 0;
	line = 0;
	attron(COLOR_PAIR(1));
	mvprintw(line++, 0, "Welcome to Bootleg 2048!");
	while (i < 16)
	{
		if (!(i % 4))
		{
			line++;
			column = 0;
			mvprintw(line++, column, "-----------------");
			mvprintw(line, column, "| ");
			column += 2;
		}
		attron(COLOR_PAIR(2));
		if (!board[i])
		{
			mvprintw(line, column, "  | ");
			i++;
		}
		else if (board[i] == 10)
		{
			mvprintw(line, column, "* | ");
			i++;
		}
		else
			mvprintw(line, column, "%d | ", board[i++]);
		column += 2;
		attron(COLOR_PAIR(1));
		mvprintw(line, column, "| ");
		column += 2;
	}
	line++;
	column = 0;
	mvprintw(line++, column, "-----------------");
}

int	add_number(int *board)
{
	int	square;
	int	number;

	if (check_board_full(board))
		return (0);
	square = (rand() % 16);
	while (board[square] != 0)
		square = (rand() % 16);
	number = (rand() % 10) + 1;
	if (number > 8)
		board[square] = 2;
	else
		board[square] = 1;
	return (1);
}
