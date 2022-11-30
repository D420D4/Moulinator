/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/06 00:16:25 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int cmp(char **c1, char **c2)
{
	int	i;

	i = 0;
	while (*(c1 + i) && *(c2 + i))
	{
		if (strcmp(c1[i], c2[i]))
			return (0);
		i++;
	}
	return (1);
}

void free_tab(char	**s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}


int	main()
{

	struct rlimit l;

	getrlimit(RLIMIT_AS, &l);
	l.rlim_cur = 100000000;
	l.rlim_max = 100000000;
	setrlimit(RLIMIT_AS, &l);
	char s[100000];
	int	i;
	i = 0;
	while (i < 99999)
	{
		s[i] = 'a' + (rand()%26);
		i++;
	}
	s[99999] = 0;
	i = 0;
	char **ss[65536];
	while (i < 65536)
	{
		printf("{{{{{{{{{{{%d}}}}}}}}}}}\n", i);
		ss[i] = FT_FUNCTION(s, 'c');
		if (!ss)
		{
			i--;
			while (i >= 0)
			{
				free_tab(ss[i]);
				i--;
			}
			return (1);
		}
		i++;
	}
	i--;
	while (i >= 0)
	{
		free_tab(ss[i]);
		i--;
	}

	return (0);
}
