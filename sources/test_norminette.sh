# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_norminette.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 22:29:35 by plefevre          #+#    #+#              #
#    Updated: 2021/11/28 23:24:22 by plefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

test_norminette()
{
	shopt -s extglob
	files=$1
	print_line
	print_title_2 "Norminette on : $files"
	tput bold
	tput setaf 220	
	printf "%-40s%-16s%-16s\n" "Filename" "Norminette" "Nb functions"
	tput sgr0
	tput setaf 221
	printf -- "---------------------------------------------------------------------------------------------\n";
	
	for file in $files; do
		tput setaf 221
		file_a=`echo $file | sed "s|${FOLDER}/||g"`
		printf "%-40s" $file_a;
		res=`norminette -R CheckForbiddenSourceHeader $file | grep "OK\!" | wc -l`
		if [[ $res == 0 ]]; then
			tput setaf 1
			nb_err=`norminette -R CheckForbiddenSourceHeader $file | wc -l`
			((nb_err -= 1))
			printf "%-16s" "FAIL[$nb_err]"
		else
			tput setaf 2
			printf "%-16s" "SUCESS"
		fi
		tput setaf 221
		nb=`grep -E "^\{" $file | wc -l`
		bar=""
		for x in `seq 1 $nb` ; do
			bar="█$bar"
		done
		printf "%-3s%-13s" $nb $bar
		printf "\n"

	done;
}
