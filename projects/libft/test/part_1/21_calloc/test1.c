/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 13:20:17 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		j = 64;
	int		i;
	int		k;
	void	*c;

	while (j-- > 0)
	{
		i = 64;
		while (i-- > 0)
		{
			k = 0;
			c = FT_FUNCTION(i, j);
			if (c == 0)
			{
				printf("Malloc failed");
				printf("nmemb : %d  size : %d", i, j);
				return (0);
			}
			while (k < i * j)
			{
				if (*((unsigned char*)(c + k)))
				{
					printf("FAILED on a simple nmemb : %d  size : %d", i, j);
					return (0);
				}
				k++;
			}
			free (c);
		}

	}
	return (1);
}
