/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_board_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:58:07 by chehir            #+#    #+#             */
/*   Updated: 2026/07/23 15:43:42 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/2048.h"

int	move_up(int *board, int index)
{
	int	moved;

	if (!board[index])
		return (0);
	moved = 0;
	while (index >= 4)
	{
		if (board[index - 4])
			return (moved);
		board[index - 4] = board[index];
		board[index] = 0;
		moved = 1;
		index -= 4;
	}
	return (moved);
}

int	move_down(int *board, int index)
{
	int	moved;

	if (!board[index])
		return (0);
	moved = 0;
	while (index < 12)
	{
		if (board[index + 4])
			return (moved);
		board[index + 4] = board[index];
		board[index] = 0;
		moved = 1;
		index += 4;
	}
	return (moved);
}

int	move_left(int *board, int index)
{
	int	moved;

	if (!board[index])
		return (0);
	moved = 0;
	while (index % 4)
	{
		if (board[index - 1])
			return (moved);
		board[index - 1] = board[index];
		board[index] = 0;
		moved = 1;
		index--;
	}
	return (moved);
}

int	move_right(int *board, int index)
{
	int	moved;

	if (!board[index])
		return (0);
	moved = 0;
	while ((index + 1) % 4)
	{
		if (board[index + 1])
			return (moved);
		board[index + 1] = board[index];
		board[index] = 0;
		moved = 1;
		index++;
	}
	return (moved);
}

int	move_board(int *board, char direction)
{
	int	output;
	int	i;

	output = 0;
	if (direction == 'w')
	{
		i = 0;
		while (i < 16)
			output += move_up(board, i++);
	}
	else if (direction == 'a')
	{
		i = 0;
		while (i < 16)
			output += move_left(board, i++);
	}
	else if (direction == 's')
	{
		i = 15;
		while (i >= 0)
			output += move_down(board, i--);
	}
	else if (direction == 'd')
	{
		i = 15;
		while (i >= 0)
			output += move_right(board, i--);
	}
	return (output);
}
