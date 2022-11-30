/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 10:43:23 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	main()
{
	int	i;

	i = -1;
	while (i < 256)
	{
		if (!!ft_isprint(i) != !!isprint(i))
		{
			printf("FAILED on %d (%c) Real function: %d   Your function  %d", i, i, isprint(i), ft_isprint(i));

			return (0);
		}
		i++;
	}
	return (1);
}
