/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:26:22 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 10:46:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	blackjack(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == 'J'
			|| *s == 'Q'
			|| *s == 'K'
			|| *s == 'D')
			count += 10;
		else if (*s == 'A')
		{
			if (count <= 10)
				count += 11;
			else
				count += 1;
		}
		else if (isdigit(*s))
			count += *s - '0';
		s++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	int	count;

	count = 0;
	if (ac == 2)
	{
		count = blackjack(av[1]);
		if (count == 21)
			printf("Blackjack!\n");
		else
			printf("%d\n", count);
	}
	else
		printf("\n");
}
