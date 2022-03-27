/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:21:45 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/06 09:16:51 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int n, int *board)
{
	int		i;
	int		j;
	char	printable_char;

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			if (board[i] == j)
			{
				printable_char = j + 47;
				write(1, &printable_char, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	place(int row, int col, int *board)
{
	int	i;

	i = 1;
	while (i <= row - 1)
	{
		if (board[i] == col)
			return (0);
		else
		{
			if ((board[i] - col) == (i - row))
				return (0);
			if ((board[i] - col) == - (i - row))
				return (0);
			if (- (board[i] - col) == (i - row))
				return (0);
			if (- (board[i] - col) == - (i - row))
				return (0);
		}
		i++;
	}
	return (1);
}

void	queen(int row, int n, int *board, int *count)
{
	int	col;

	col = 1;
	while (col <= n)
	{
		if (place(row, col, board))
		{
			board[row] = col;
			if (row == n)
			{
				*count += 1;
				print(n, board);
			}
			else
				queen(row + 1, n, board, count);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[20];
	int	count;

	count = 0;
	queen(1, 10, board, &count);
	return (count);
}
