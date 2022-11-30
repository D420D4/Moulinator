/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 17:19:30 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		nb = 4096; 
	int		j = 0;
	int		i;
	int		t1;
	int		t2;
	char	c1[4];
	char	c2[4];
	char	*s;

	while (nb-- > 0)
	{
		t1 = rand() % 4;
		t2 = rand() % 4;

		j = 0;

		while (j < 4)
		{
			if (j < t1)
				c1[j] = rand() % 26 + 'a';
			if (j < t2)
				c2[j] = rand() % 26 + 'a';
			j++;
		}
		
		c1[t1] = 0;
		c2[t2] = 0;
		
		s = ft_strjoin(c1, c2);

		if (!(memcmp(s, c1, t1) == 0 && memcmp(s + t1, c2, t2) == 0 && s[t1 + t2] == 0))
		{
			printf("FAILED on a simple (relatif)");
			return (0);
		}

		free(s);

	}
	return (1);
}
