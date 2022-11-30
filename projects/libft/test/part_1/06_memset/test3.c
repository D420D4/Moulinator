/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 11:22:50 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define FUNCTION(x, y, z) memset(x, y, z)
#define FT_FUNCTION(x, y, z) ft_memset(x, y, z)

int	main()
{
	char	s1[64];
	void	*p1;
	void	*p2;
	int		i = 64;

	while (i >= 0)
	{
		memset(s1, '4', 64);
		
		p1 = FUNCTION(s1, i, i);
		p2 = FUNCTION(s1, i, i);
		
		if (p1 != p2)
		{
			printf("FAILED bad return value");
			return (0);
		}
		i--;
	}
	return (1);
}
