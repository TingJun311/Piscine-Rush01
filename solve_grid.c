/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:30:46 by ctingjun          #+#    #+#             */
/*   Updated: 2022/08/28 12:30:49 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		checkgrid(int grid[4][4], int *in_num);

int	lookfor0(int grid[4][4], int *r, int *c)
{
	*r = 0;
	*c = 0;
	while (*r < 4)
	{
		*c = 0;
		while (*c < 4)
		{
			if (grid[*r][*c] == 0)
				return (1);
			*c += 1;
		}
		*r += 1;
	}
	return (0);
}

int	safecol(int grid[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	saferow(int grid[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	checksafe(int grid[4][4], int r, int c, int num)
{
	if (((saferow(grid, r, num)) && (safecol(grid, c, num))
			&& (grid[r][c] == 0)))
		return (1);
	return (0);
}

int	solve_rest(int grid[4][4], int *input)
{
	int	row;
	int	col;
	int	n;

	n = 1;
	if ((lookfor0(grid, &row, &col) == 0) && (checkgrid(grid, input) == 1))
		return (1);
	while (n <= 4)
	{
		if (checksafe(grid, row, col, n))
		{
			grid[row][col] = n;
			if (solve_rest(grid, input) == 1)
				return (1);
			grid[row][col] = 0;
		}
		n++;
	}
	return (0);
}
