#!/bin/bash

#source "$MOULINATOR_FOLDER/sources/display.sh" 

makefile_test()
{
	makefile=$1
	score=0
	max_score=3

	export MAX_SCORE=$(($MAX_SCORE + $max_score))

	print_line
	print_title_2 "Makefile test : $makefile"
	if [ ! -f $makefile ]; then
		print_error_msg "Makefile not found"
		return 1
	fi
	((score += 1))
	run_s "/exec/makefile_test $makefile"
	((score += 2))
	((score -= $(wc -l < .errout)))
	print_error_from_file .errout	
	#cat	.out	
	export SCORE=$(($SCORE + $score))
	c_file=`find . -name "*.c"`
	for file in $c_file; do
		filename=`basename $file`	
		res=`grep $filename $makefile | wc -c`
		if [[ $res == 0 ]]; then
			print_error_msg "File not found in Makefile : $file"
			((score -= 1))
		fi
	done;

	tput setaf 30	
	printf "%-20s :  " "Check all"
	print_result `grep -E "^all.*:" $makefile | wc -l` 1
	printf "\n"

	tput setaf 30	
	printf "%-20s :  " "Check \$(NAME)"
	print_result `grep -E "^.\(NAME\).*:" $makefile | wc -l` 1
	printf "\n"

	tput setaf 30	
	printf "%-20s :  " "Check clean"
	print_result `grep -E "^clean.*:" $makefile | wc -l` 1
	printf "\n"

	tput setaf 30	
	printf "%-20s :  " "Check fclean"
	print_result `grep -E "^fclean.*:" $makefile | wc -l` 1
	printf "\n"

	tput setaf 30	
	printf "%-20s :  " "Check re"
	print_result `grep -E "^re.*:" $makefile | wc -l` 1
	printf "\n"


}	
