/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:13:38 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 11:33:03 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define FUNCTION(x, y, z) memset(x, y, z)
#define FT_FUNCTION(x, y, z) ft_memset(x, y, z)

int	main()
{
	FT_FUNCTION(0, '4', 42);
	return (1);
}
