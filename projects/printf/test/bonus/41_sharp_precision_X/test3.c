/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:47:33 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/12 06:02:56 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int ac, char** av)
{
	printf("[%d]", FUNCTION("%#.X",42));
	fflush(stdout);

	printf("[%d]", FUNCTION("%#0.0X",42));
	fflush(stdout);
	
	printf("[%d]", FUNCTION("%#10.3X",42));
	fflush(stdout);
	
	printf("[%d]", FUNCTION("%#3.10X",42));
	fflush(stdout);
	
	printf("[%d]", FUNCTION("%#100.10X",42));
	fflush(stdout);
}
