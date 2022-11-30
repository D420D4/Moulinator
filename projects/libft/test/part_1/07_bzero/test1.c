/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 11:49:34 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define FUNCTION(x, y) bzero(x, y)
#define FT_FUNCTION(x, y) ft_bzero(x, y)

int	main()
{
	char	s1[64];
	char	s2[64];
	int		i = 64;

	while (i >= 0)
	{
		memset(s1, '4', 64);
		memset(s2, '4', 64);
		
		FUNCTION(s1, i);
		FT_FUNCTION(s2, i);
		
		if (memcmp(s1, s2, 64))
		{
			printf("FAILED on a simple test");
			return (0);
		}
		i--;
	}
	return (1);
}
