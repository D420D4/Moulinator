/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 18:19:07 by plefevre         ###   ########.fr       */
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

	if (FT_FUNCTION("1","2"))
	{
		printf("Bah allors? on ne protege pas ses malloc????");
		return (0);
	}

	return (1);
}
