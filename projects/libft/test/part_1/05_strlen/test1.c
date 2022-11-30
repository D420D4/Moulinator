/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/05 20:13:12 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define FUNCTION(x) strlen(x)
#define FT_FUNCTION(x) ft_strlen(x)

int	main()
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (0);
	*s = 0;

	if (!!FT_FUNCTION(s) != !!FUNCTION(s))
	{
		printf("FAILED on %s. Real function: %d   Your function  %d", s, (int) FUNCTION(s), FT_FUNCTION(s));
		free (s);
		return (0);
	}
	free (s);
	return (1);
}
