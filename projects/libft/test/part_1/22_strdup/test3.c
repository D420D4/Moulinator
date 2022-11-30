/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 16:53:21 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	void	*c;
	struct rlimit l;
	
	getrlimit(RLIMIT_AS, &l);
	l.rlim_cur = 0;
	l.rlim_max = 0;
	setrlimit(RLIMIT_AS, &l);

	c = FT_FUNCTION("test");
	
	if (c != 0)
	{
		printf("Not returning 0");
		return (0);
	}


	return (1);
}
