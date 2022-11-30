/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 16:53:18 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		k;
	char	*c;
	
	struct rlimit l;
	
	getrlimit(RLIMIT_AS, &l);
	l.rlim_cur = 0;
	l.rlim_max = 0;
	setrlimit(RLIMIT_AS, &l);

	c = FT_FUNCTION("123", 1, 1);
	
	if (c)
	{
		printf("FAILED on not failling the faillure of malloc");
		return (0);
	}
	free (c);
	return (1);
}
