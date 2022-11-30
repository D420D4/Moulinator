/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:47:33 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/12 05:32:24 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int ac, char** av)
{
	printf("[%d]", FUNCTION("%00.20d", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%0.20d", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%020.20d", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%010.d", 0));
	fflush(stdout);
}
