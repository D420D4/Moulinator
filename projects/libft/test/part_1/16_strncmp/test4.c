/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 20:16:58 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		j = 256;
	int		i = 1;
	char	*s0;
	char	*s1;
	int		t1;
	int		t2;

	s0 = "";
	s1 = "leau ca mouille";

	t1 = FUNCTION(s0, s1, i);
	t2 = FT_FUNCTION(s0, s1, i);
	
	if (t1 > 0 && t2 < 0 || t2 > 0 && t1 < 0)
	{
		printf("FAILED on a simple test : Real function : %d your function : %d", t1, t2);
		return (0);
	}

	return (1);
}
