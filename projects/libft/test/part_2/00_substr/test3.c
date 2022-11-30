/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 16:44:39 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main()
{
	int		k;
	char	*c;

	c = FT_FUNCTION("qbc", 6, 3);
	
	if(!c)
		return (0);

	if (strcmp(c, ""))
	{
		printf("FAILED on a simple");
		return (0);
	}
	free (c);
	return (1);
}
