/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_board_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:00:04 by chehir            #+#    #+#             */
/*   Updated: 2026/07/23 15:43:40 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/2048.h"

int	merge_up(int *board, int index)
{
	int	i;

	if (!board[index] || index < 4)
		return (0);
	i = index - 4;
	while (i >= 0)
	{
		if (board[i] == board[index])
		{
			board[i] += 1000001;
			board[index] = 0;
			return (1);
		}
		else if (board[i])
			return (0);
		i -= 4;
	}
	return (0);
}

int	merge_down(int *board, int index)
{
	int	i;

	if (!board[index] || index >= 12)
		return (0);
	i = index + 4;
	while (i < 16)
	{
		if (board[i] == board[index])
		{
			board[i] += 1000001;
			board[index] = 0;
			return (1);
		}
		else if (board[i])
			return (0);
		i += 4;
	}
	return (0);
}

int	merge_left(int *board, int index)
{
	int	i;

	if (!board[index] || !(index % 4))
		return (0);
	i = index;
	while (i % 4)
	{
		i--;
		if (board[i] == board[index])
		{
			board[i] += 1000001;
			board[index] = 0;
			return (1);
		}
		else if (board[i])
			return (0);
	}
	return (0);
}

int	merge_right(int *board, int index)
{
	int	i;

	if (!board[index] || (index % 4 == 3))
		return (0);
	i = index;
	while ((i + 1) % 4)
	{
		i++;
		if (board[i] == board[index])
		{
			board[i] += 1000001;
			board[index] = 0;
			return (1);
		}
		else if (board[i])
			return (0);
	}
	return (0);
}
int	merge_board(int *board, char direction)
{
	int	output;
	int	i;

	output = 0;
	if (direction == 'w')
	{
		i = 0;
		while (i < 16)
			output += merge_up(board, i++);
	}
	if (direction == 'a')
	{
		i = 0;
		while (i < 16)
			output += merge_left(board, i++);
	}
	else if (direction == 's')
	{
		i = 15;
		while (i >= 0)
			output += merge_down(board, i--);
	}
	else if (direction == 'd')
	{
		i = 15;
		while (i >= 0)
			output += merge_right(board, i--);
	}
	return (output);
}
