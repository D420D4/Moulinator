/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 18:48:21 by plefevre         ###   ########.fr       */
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


int	main()
{

	struct rlimit l;

	getrlimit(RLIMIT_AS, &l);
	l.rlim_cur = 0;
	l.rlim_max = 0;
	setrlimit(RLIMIT_AS, &l);


	if (FT_FUNCTION("123", 'q'))
	{
		printf("MALOCCCCCCCCCCCC!!!!!!!!!!!!!!");
		return (0);
	}

	return (1);
}
