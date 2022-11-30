/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 12:54:21 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char *itoa(int ii)
{
	char	*c;
	long	i;
	int	j;
	int	k;

	i = (long)ii;
	
	c = malloc(16);
	if (!c)
		return (0);
	j = 1;
	while (i / j > 9 || i / j < -9)
	{
		j *= 10;
	}
	
	k = 0;
	if (i < 0)
	{
		c[0] = '-';
		i *= -1;
		k++;
	}
	while (j != 0)
	{
		c[k] = (i / j) % 10 + '0';
		k++;
		j /= 10;
	}
	c[k] = 0;
	return (c);
}

int	main()
{
	int		n;
	char	*nc;
	
	n = -2147483648; 
	nc = itoa(n);
	if (n != FT_FUNCTION(nc))
	{
		printf("FAILED on border  : %d %s your function %d", n, nc, FT_FUNCTION(nc));
		return (0);
	}
	free(nc);

	return (1);
}
