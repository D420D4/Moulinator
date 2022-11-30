# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_no_folder.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 22:29:21 by plefevre          #+#    #+#              #
#    Updated: 2021/12/01 19:39:46 by plefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

test_no_folder()
{
	print_line
	print_title_2 "Check directories"

	res=`ls -l | grep '^d' | wc -l`
	if [[ $res != 0 ]]; then
		print_error_msg "directorie found"
	fi
}
