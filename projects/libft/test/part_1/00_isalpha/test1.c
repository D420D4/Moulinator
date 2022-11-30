/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 10:31:12 by plefevre         ###   ########.fr       */
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
		if (!!ft_isalpha(i) != !!isalpha(i))
		{
			printf("FAILED on %d (%c) Real function: %d   Your function  %d", i, i, isalpha(i), ft_isalpha(i));

			return (0);
		}
		i++;
	}
	return (1);
}
