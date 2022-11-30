/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 23:23:10 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_in(char	*s, char c)
{
	int	i = 0;

	while (*(s + i))
	{
		if (*(s + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static int	cmp(char *o, char *f, char *s)
{
	int	i;
	int	j;
	
	i = 0;
	while (is_in(s, o[i]))
		i++;
	j = 0;
	while (s[i + j])
		j++;
	while (is_in(s, o[i + j]) && j > 0)
		j--;
	return (memcmp(o + i, f, j) == 0);
}


int	main()
{
	char	*c1;
	char	*c2;
	char	*s;

	c2 = ".2sa";
	c1 = "";
	s = FT_FUNCTION(c1, c2);

	if (*s != 0)
	{
		printf("FAILED on a simple (relatif)");
		free (s);
		return (0);
	}
	free(s);
	return (1);
}
