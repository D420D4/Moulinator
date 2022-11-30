/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 23:04:31 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		j = 0;
	int		i;
	char	*c;
	char	c2[4096];
	char	s[4096];

	while (j < 4096)
	{
		s[j] = rand() % 254 + 1;
		j++;
	}
	s[4095] = 0;
	i = rand() % 2048;
	j = rand() % 2048;
	c = FT_FUNCTION(s, i, j);
	if (!c)
		return (0);
	memcpy(c2, s + i, j);
	c2[j] = 0;

	if (strcmp(c, c2))
	{
		printf("FAILED on a simple/complex (relatif)");
		free(c);
		return (0);
	}
	free(c);
	return (1);
}
