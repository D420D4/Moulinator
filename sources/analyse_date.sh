# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    analyse_date.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 22:31:15 by plefevre          #+#    #+#              #
#    Updated: 2021/11/28 22:17:49 by plefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

anada_do_line()
{
	date_c=`grep  "#+#    #+#" $1 | sed "s/.*Created: //" | sed 's/ .*//'`
	date_u=`grep  "###   ########.fr" $1 | sed "s/.*Updated: //" | sed 's/ .*//'`

	printf "%-12s %-12s " $date_c $date_u 
	run_s1 "/exec/print_date $date_c $date_u 80"
}


analyse_date()
{
	shopt -s extglob
	files=$1
	print_line
	print_title_2 "Analyse date : $files"
	tput bold
	tput setaf 220	
	printf "%-40s %-12s %-12s   Beautiful things\n" "Filename" "Created on" "Updated on"
	tput sgr0
	tput setaf 221
	printf -- "----------------------------------------------------------------------------------------\n";
	for file in $files; do
		file_a=`echo $file | sed "s|${FOLDER}/||g"`
		printf "%-40s " $file_a;
		anada_do_line $file
		printf "\n"
	done;
}
