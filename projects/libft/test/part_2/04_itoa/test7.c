/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 18:56:22 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main()
{
	struct rlimit l;

	getrlimit(RLIMIT_AS, &l);
	l.rlim_cur = 0;
	l.rlim_max = 0;
	setrlimit(RLIMIT_AS, &l);

	if (FT_FUNCTION(0))
	{
		printf("malloc :(");
		return (0);
	}

	return (1);
}
