/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 11:01:58 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int	j = 256;

	while (j-- > 0)
	{
		if (FUNCTION(j) != FT_FUNCTION(j))
		{
			printf("FAILED on a simple test : %d (%c) Real function : %d  your function %d", j, j, FUNCTION(j), FT_FUNCTION(j));
			return (0);
		}
		j--;
		
	}
	return (1);
}
