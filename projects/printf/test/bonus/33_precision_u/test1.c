/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:47:33 by plefevre          #+#    #+#             */
/*   Updated: 2021/12/11 18:16:44 by plefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int ac, char** av)
{
	printf("[%d]", FUNCTION("%0.2u", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%.20u", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%0.0u", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%20.20u", 0));
	fflush(stdout);
	printf("[%d]", FUNCTION("%10.u", 0));
	fflush(stdout);
}
