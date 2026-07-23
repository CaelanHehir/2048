/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:04:30 by chehir            #+#    #+#             */
/*   Updated: 2026/07/23 15:43:36 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/2048.h"

int	check_board_full(int *board)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!board[i++])
			return (0);
	}
	return (1);
}

int	check_possible_moves(int *board)
{
	int	i;

	i = 1;
	if (!check_board_full(board))
		return (1);
	while (i <= 14)
	{
		if (board[i] == board[i - 1] || board[i] == board[i + 1])
			return (1);
		if (!(i % 2))
			i += 3;
		else
			i++;
	}
	i = 4;
	while (i < 12)
	{
		if (board[i] == board[i - 4] || board[i] == board[i + 4])
			return (1);
		i++;
	}
	return (0);
}

void	check_merge(int *board)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (board[i] > 1000000)
			board[i] -= 1000000;
		i++;
	}
}

int	check_win(int *board)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (board[i] == 10)
			return (1);
		i++;
	}
	return (0);
}
