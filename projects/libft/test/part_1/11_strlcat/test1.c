/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 14:43:36 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	char	s0[16];
	char	s1[16];
	char	s2[16];
	int		t1;
	int		t2;
	int		i;
	int		j = 256;

	while (j-- > 0)
	{
		i = 15;
		while (i >= 0)
		{
			s0[i] = (rand() % 16)*16;
			s1[i] = (rand() % 16)*16;
			s2[i] = s1[i];
			i--;
		}
		s0[15] = 0;
		s1[15] = 0;
		s2[15] = 0;
		i = rand() % 17;

		t1 = FUNCTION(s1, s0, i);
		t2 = FT_FUNCTION(s2, s0, i);

		if (memcmp(s1, s2, i) || t2 != t1)
		{
			printf("FAILED on a simple test");
			return (0);
		}
		j--;
		
	}
	return (1);
}
