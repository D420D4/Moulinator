/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 15:01:22 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		j = 256;
	int		i;
	char	s0[256];
	int		c;
	char	*s1;
	char	*s2;

	while (j-- > 0)
	{
		i = 0;
		while (i < 256)
			s0[i++] = (rand()%16) * 16;
		s0[255] = 0;
		c = (rand() % 18) * 16 - 16;

		s1 = FUNCTION(s0, c);
		s2 = FT_FUNCTION(s0, c);

		if (s1 != s2)
		{
			printf("FAILED on a simple test : Real function : %p your function : %p", s1, s2);
			return (0);
		}
		j--;
		
	}
	return (1);
}
