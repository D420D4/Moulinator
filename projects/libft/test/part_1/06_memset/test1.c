/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 11:11:56 by plefevre         ###   ########.fr       */
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
	char	s2[64];
	void	*p1;
	void	*p2;
	int		i = 64;

	while (i >= 0)
	{
		memset(s1, '4', 64);
		memset(s2, '4', 64);
		
		p1 = FUNCTION(s1, '2', i);
		p2 = FT_FUNCTION(s2, '2', i);
		
		if (memcmp(s1, s2, 64) || (char *)p2 != s2)
		{
			printf("FAILED on a simple test");
			return (0);
		}
		i--;
	}
	return (1);
}
