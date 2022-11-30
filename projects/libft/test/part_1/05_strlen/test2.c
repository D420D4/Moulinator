/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/01 10:56:10 by plefevre         ###   ########.fr       */
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

	s = "dsqldnklkslqnsoiqnklqsnlk";

	if (!!FT_FUNCTION(s) != !!FUNCTION(s))
	{
		printf("FAILED on %s. Real function: %d   Your function  %d", s, (int) FUNCTION(s), FT_FUNCTION(s));
		return (0);
	}
	return (1);
}
