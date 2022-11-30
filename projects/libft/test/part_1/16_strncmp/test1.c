/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 16:13:19 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		j = 256;
	int		i;
	char	s0[256];
	char	s1[256];
	int		t1;
	int		t2;

	while (j-- > 0)
	{
		i = 0;
		while (i < 256)
		{
			s0[i] = rand() % 256;
			s1[i] = s0[i];
			if (rand() % 256 == 0)
				s1[i] = rand() % 256;
			i++;
		}
	
		s0[255] = 0;
		s1[255] = 0;

		i = rand() % 256;

		t1 = FUNCTION(s0, s1, i);
		t2 = FT_FUNCTION(s0, s1, i);

		if (t1 > 0 && t2 < 0 || t2 > 0 && t1 < 0)
		{
			printf("FAILED on a simple test : Real function : %d your function : %d", t1, t2);
			return (0);
		}
		j--;
		
	}
	return (1);
}
