/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:31:52 by ctingjun          #+#    #+#             */
/*   Updated: 2022/08/28 18:37:07 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		solve_rest(int grid[4][4], int *input);

void	display_grid(int grid[4][4]);

void	solve_input_4_1(int grid[4][4], int *input, int i)
{
	int	fill;

	fill = 0;
	while ((input[i]) && i <= 15)
	{
		if ((input[i] == 4) && ((i >= 8 && i <= 11)))
		{
			while (fill < 4)
			{
				grid[i % 4][fill] = fill + 1;
				fill++;
			}
		}
		fill = 4;
		if ((input[i] == 4) && ((i >= 12 && i <= 15)))
		{
			while (fill > 0)
			{
				grid[i % 4][4 - fill] = fill;
				fill--;
			}
		}
		i++;
	}
}

void	solve_input_4_0(int grid[4][4], int *input)
{
	int	i;
	int	fill;

	i = 0;
	fill = 0;
	while ((input[i]) && i < 8)
	{
		if ((input[i] == 4) && ((i >= 0 && i <= 3)))
		{
			while (fill++ < 4)
				grid[fill][i] = fill + 1;
		}
		fill = 4;
		if ((input[i] == 4) && ((i >= 4 && i <= 7)))
		{
			while (fill-- > 0)
				grid[4 - fill][(i % 4)] = fill;
		}
		i++;
	}
	solve_input_4_1(grid, input, i);
}

void	solve_input_1(int grid[4][4], int *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((input[i] == 1) && ((i >= 0) && (i <= 3)))
			grid[0][i] = 4;
		if ((input[i] == 1) && ((i >= 4) && (i <= 7)))
			grid[3][i - 4] = 4;
		if ((input[i] == 1) && ((i >= 8) && (i <= 11)))
			grid[i - 8][0] = 4;
		if ((input[i] == 1) && ((i >= 12) && (i <= 15)))
			grid[i - 12][3] = 4;
		i++;
	}
	solve_input_4_0(grid, input);
}

int	genarate_board(int *input)
{
	int		row;
	int		col;
	int		grid[4][4];

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	solve_input_1(grid, input);
	if ((solve_rest(grid, input)) == 1)
		display_grid(grid);
	else
		write(1, "\nError No Solution Found\n\n", 27);
	return (0);
}
