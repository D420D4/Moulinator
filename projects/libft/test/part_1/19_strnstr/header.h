/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:14:09 by plefevre          #+#    #+#             */
/*   Updated: 2021/11/30 16:28:00 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <bsd/string.h>
# include <stdio.h>
# include <ctype.h>

# define FUNCTION(x, y, z) strnstr(x, y, z)
# define FT_FUNCTION(x, y, z) ft_strnstr(x, y, z)

#endif
