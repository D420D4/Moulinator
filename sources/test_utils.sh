# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_utils.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 17:33:30 by plefevre          #+#    #+#              #
#    Updated: 2021/12/10 07:52:00 by plefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

print_ok()
{
	tput setaf 2
	printf "[:-)] "
}

print_ko()
{
	tput setaf 1
	printf "[:-(] "
}

print_no()
{
	tput setaf 1
	printf "[No function]"
}

print_sf()
{
	tput setaf 1
	printf "[SeF] "
}

print_nf()
{
	tput setaf 1
	printf "[NSF] "
}

execute_valgrind()
{
	if [[ $MOULIVAL == 0 ]]; then
		eval $1
	else
		valgrind --leak-check=full -q $1
	fi
}

execute_test()
{
	if [[ $3 == 1 || $MOULIVAL == 1 ]]; then
		res=`eval valgrind --leak-check=full -q $1 $PROJECT_FOLDER`
	else
		res=`eval $1 $PROJECT_FOLDER`
	fi

	code=$?
	if [[ $code == 0 ]]; then
		print_ko
		printf "$2\n" >> /tmp/mouli_trace
		printf "$res\n" >> /tmp/mouli_trace
	elif [[ $code == 139 ]]; then
		print_sf
	else
		print_ok
	fi
}

eval_diff()
{
	res=`diff -U 3 $1 $2`
	reswc=`echo $res | wc -w`
	if [[ $reswc == 0 ]]; then
		print_ok
	else
		print_ko
		echo $res >> /tmp/mouli_trace
		printf "user\n" >> /tmp/mouli_trace
		cat $2 >> /tmp/mouli_trace
		printf "\n\nreal\n" >> /tmp/mouli_trace
		cat $1 >> /tmp/mouli_trace
		printf "\n-------------------------------------" >> /tmp/mouli_trace
	fi
}

execute_test_2()
{
	res=`eval $1`
	code=$?
	if [[ $code == 1 ]]; then
		print_nf
	elif [[ $code == 139 ]]; then
		print_ok
	else
		print_nf
	fi
	printf "$res"
}

test_compile()
{
	res=`gcc -I $1 $2 $3 -o /dev/null 2>&1`
	if [[ $res != "" ]]; then
		echo 0
		echo $res > /tmp/moulinator_test_compile
	else	
		echo 1
	fi
}
