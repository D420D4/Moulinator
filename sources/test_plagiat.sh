# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_plagiat.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 22:31:15 by plefevre          #+#    #+#              #
#    Updated: 2021/11/28 15:25:56 by plefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test_plagiat()
{
	shopt -s extglob
	files=$1
	print_line
	print_title_2 "Plagiat test : $files"
	print_title_3 "By:"
	tput setaf 220
	grep "+#+  +:+       +#+" $files | sed 's/.*By: /\t/g' | sed 's/>.*/>/g' | sort | uniq
	
	print_title_3 "Created by :"
	tput setaf 220 
	grep "#+#    #+#" *.c *.h | sed 's/.*by./\t/g' | sed 's/ .*//g' | sort | uniq

	print_title_3 "Updated by :"
	tput setaf 220
	grep "###   ########.fr" *.c *.h | sed 's/.*by./\t/g' | sed 's/ .*//g' | sort | uniq

}
