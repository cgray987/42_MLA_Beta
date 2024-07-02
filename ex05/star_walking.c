/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_walking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:48:09 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:20:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_right(int size, char arr[64][64]);
void	fill_left(int size, char left[64][64]);
void	fill_middle(int size, char arr[64][64]);

void	print_array(char arr[64][64], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			printf("%c", arr[i][j++]);
		printf("\n");
		i++;
	}
}

void	star_print(int arg)
{
	int		size;
	char	arr[64][64];
	int		i;
	int		j;

	i = 0;
	size = 4 * (arg - 1) + 1;
	while (i < size)
	{
		j = 0;
		while (j < size)
			arr[i][j++] = ' ';
		i++;
	}
	fill_left(size, arr);
	fill_right(size, arr);
	fill_middle(size, arr);
	print_array(arr, size);
}

int	main(int ac, char **av)
{
	int		arg;

	if (ac == 2)
	{
		arg = atoi(av[1]);
		if (arg == 1)
			printf("42\n");
		else
			star_print(arg);
	}
	return (0);
}
