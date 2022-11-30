/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 13:03:11 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	char	s1[500];
	char	s2[500];
	void	*p1;
	void	*p2;
	int		i = 500;

	while (i >= 0)
	{
		s1[i] = (rand() % 16) * 16;
		s2[i] = s1[i];
		i--;
	}


	i = 200;
	while (i >= 0)
	{
		p1 = FUNCTION(250 + s1, s1 + i + 150, i / 2);
		p2 = FT_FUNCTION(250 + s2, s2 + i + 150, i / 2);
		
		if (memcmp(s1, s2, 500) || (char *)p2 != s2 + 250)
		{
			printf("FAILED on a simple test (%d), ",i);
			if ((char *)p2 != s2 + 250)
				printf("bad return");
			else
				printf("difference : %d", memcmp(s1, s2, 500));
			return (0);
		}
		i--;
	}
	return (1);
}
