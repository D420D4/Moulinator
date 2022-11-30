/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 11:49:49 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define FUNCTION(x, y) bzero(x, y)
#define FT_FUNCTION(x, y) ft_bzero(x, y)

int	main()
{
	FT_FUNCTION(0, 42);
	return (1);
}
