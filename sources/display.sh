#!/bin/bash

print_title()
{
	tput setaf 14 
	printf "\n    ███╗   ███╗ ██████╗ ██╗   ██╗██╗     ██╗███╗   ██╗ █████╗ ████████╗ ██████╗ ██████╗ 
    ████╗ ████║██╔═══██╗██║   ██║██║     ██║████╗  ██║██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗
    ██╔████╔██║██║   ██║██║   ██║██║     ██║██╔██╗ ██║███████║   ██║   ██║   ██║██████╔╝
    ██║╚██╔╝██║██║   ██║██║   ██║██║     ██║██║╚██╗██║██╔══██║   ██║   ██║   ██║██╔══██╗
    ██║ ╚═╝ ██║╚██████╔╝╚██████╔╝███████╗██║██║ ╚████║██║  ██║   ██║   ╚██████╔╝██║  ██║
    ╚═╝     ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n\n"
}
	
print_line()
{
	tput setaf 30
	printf -- "---------------------------------------------------------------------------------------------\n"
}

print_text_inline()
{
	tput setaf 14
	tput bold
	printf "$1"
	printf " : "
	tput sgr0
	tput setaf 30
	printf "$2"
	printf "\n";
}

print_error_msg()
{
	tput setaf 1
	tput bold
	printf "%-10s : " "ERROR"
	tput sgr0
	tput setaf 30 
	printf "$1"
	printf "\n";
}

print_warning_msg()
{
	tput setaf 214 
	tput bold
	printf "%-10s : " "WARNING"
	tput sgr0
	tput setaf 30 
	printf "$1"
	printf "\n";
}

print_result()
{
	if [[ $1 != $2 ]]; then
		tput setaf 1
		printf "%-8s" "FAILED"
	else
		tput setaf 2
		printf "%-8s" "SUCCESS"
	fi
}

print_title_2()
{
	tput setaf 14
	tput bold
	printf "$1\n"
	tput sgr0
}

print_title_3()
{
	tput setaf 14
	printf "$1\n"
	tput sgr0
}

print_score()
{
	printf "Score : $SCORE/$MAX_SCORE"
}


print_error_from_file()
{

	while IFS= read -r line; do
		if [[ $line == FATAL\ :\ * ]]; then
			tput setaf 1
			tput bold
			printf "%-12s" "[FATAL]"
			tput sgr0
			tput setaf 30
			printf ": ${line:8}\n"
		elif [[ $line == WARNING\ :\ * ]]; then
			tput setaf 209
			tput bold
			printf "%-12s" "[WARNING]"
			tput sgr0
			tput setaf 30
			printf ": ${line:10}\n"
		else
			tput setaf 209
			tput bold
			printf "%-12s" "[INFO]"
			tput sgr0
			tput setaf 30
			printf ": $line\n"
		fi

	done < $1;
}
