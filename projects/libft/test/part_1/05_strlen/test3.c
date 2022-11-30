/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 10:56:23 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define FUNCTION(x) strlen(x)
#define FT_FUNCTION(x) ft_strlen(x)

int	main()
{
	char	*s;
	int		i;
	int		j;

	s = malloc(5000);
	
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 5000)
		{
			s[j] = rand() %128;
			j++;
		}
		s[4999] = 0;
		if (!!FT_FUNCTION(s) != !!FUNCTION(s))
		{
			printf("FAILED on %s. Real function: %d   Your function  %d", s, (int) FUNCTION(s), FT_FUNCTION(s));
			free(s);
			return (0);
		}
		i++;
	}
	free(s);
	return (1);
}
