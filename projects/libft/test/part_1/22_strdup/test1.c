/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 20:18:45 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		j = 0;
	char	*c;
	char	s[4096];

	while (j < 4096)
	{
		s[j] = rand() % 254 + 1;
		j++;
	}
	s[4095] = 0;
	c = FT_FUNCTION(s);
	if (!c)
		return (0);
	if (strcmp(c, s))
	{
		printf("FAILED on a simple");
		free (c);
		return (0);
	}
	free (c);
	return (1);
}
