/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 12:22:11 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	char	s0[64];
	char	s1[64];
	char	s2[64];
	void	*p1;
	void	*p2;
	int		i = 64;

	while (i >= 0)
		s0[i--] = rand() % 128;
	
	i = 64;
	while (i >= 0)
	{
		memset(s1, '4', 64);
		memset(s2, '4', 64);
		
		p1 = FUNCTION(s1, s0, i);
		p2 = FT_FUNCTION(s2, s0, i);
		
		if (memcmp(s1, s2, 64) || (char *)p2 != s2)
		{
			printf("FAILED on a simple test");
			return (0);
		}
		i--;
	}
	return (1);
}
