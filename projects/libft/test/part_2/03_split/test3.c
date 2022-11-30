/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 23:19:49 by plefevre         ###   ########.fr       */
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

void free_tab(char **c)
{
	int i;

	i = 0;
	while (c[i])
	{
		free (c[i]);
		i++;
	}
	free (c);
}


int	main()
{
	char	**c1;
	char	**c2;

	c1 = FT_FUNCTION("256", 0);
	c2 = malloc(6 * sizeof(char *));

	c2[0] = strdup("256");
	c2[1] = 0;


	if (!cmp(c1, c2))
	{
		printf("FAILED with 0");
		free_tab(c1);
		free_tab(c2);
		return (0);
	}

	free_tab(c1);
	free_tab(c2);

	
	return (1);
}
