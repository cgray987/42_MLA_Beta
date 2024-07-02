/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:14:16 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:52:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//creates right sided pyramid for every other row
void	fill_right(int size, char arr[64][64])
{
	int	i;
	int	row;
	int	limit;

	limit = 1;
	row = 0;
	while (row < size)
	{
		i = size - 1;
		while (i >= size - limit)
		{
			arr[row][i] = '*';
			i -= 2;
		}
		if (row < (size - 1) / 2)
			limit += 2;
		else
			limit -= 2;
		row += 2;
	}
}

//sometimes norminette is very dumb
void	fill_left_bottom(int size, char left[64][64], int limit, int row)
{
	int	i;

	while (row < size)
	{
		i = limit + 1;
		while (i >= 0)
		{
			left[row][i] = '*';
			i -= 2;
		}
		limit -= 2;
		row++;
	}
}

//n = 4, size = 13
//creates left sided pyramid
void	fill_left(int size, char left[64][64])
{
	int	i;
	int	limit;
	int	row;

	row = 0;
	limit = 1;
	while (row <= (size - 1) / 2)
	{
		i = 0;
		while (i < limit)
		{
			left[row][i] = '*';
			i += 2;
		}
		limit += 2;
		row++;
	}
	limit -= 6;
	fill_left_bottom(size, left, limit, row);
}

//creates hourglass shape every other row
void	fill_middle(int size, char arr[64][64])
{
	int	i;
	int	limit;
	int	row;

	limit = size;
	row = 0;
	while (row < size)
	{
		i = size - limit;
		while (i < limit)
			arr[row][i++] = '*';
		if (row < (size - 1) / 2)
			limit -= 2;
		else
			limit += 2;
		row += 2;
	}
}
