/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:47:33 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/12 07:22:40 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int ac, char** av)
{
	printf("[%d]", FUNCTION("__%.0s__",0));
	fflush(stdout);
	printf("[%d]", FUNCTION("__%.1s__",0));
	fflush(stdout);
	printf("[%d]", FUNCTION("__%.2s__",0));
	fflush(stdout);
	printf("[%d]", FUNCTION("__%.3s__",0));
	fflush(stdout);
	printf("[%d]", FUNCTION("__%.4s__",0));
	fflush(stdout);
	printf("[%d]", FUNCTION("__%.5s__",0));
	fflush(stdout);
	printf("[%d]", FUNCTION("__%.6s__",0));
	fflush(stdout);
}
