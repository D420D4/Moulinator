/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 23:02:03 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	char	s0[64];
	char	s1[64];
	char	s2[64];
	int		t1;
	int		t2;
	int		i = 64;

	while (i >= 0)
		s0[i--] = rand() % 128;
	s0[63] = 0;
	i = 64;
	while (i >= 64)
	{
		memset(s1, '4', 64);
		memset(s2, '4', 64);
		s1[63] = 0;
		s2[63] = 0;
		t1 = FUNCTION(s1, s0, i);
		t2 = FT_FUNCTION(s2, s0, i);
		
		if (memcmp(s1, s2, 64) || t2 != t1)
		{
			printf("FAILED on a simple test");
			return (0);
		}
		i--;
	}
	return (1);
}
