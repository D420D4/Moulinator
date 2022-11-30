#!/bin/bash


do_test()
{
	if [[ $1 == *"/"* ]]; then
		do_test_sub	$1
	else
		do_test_group $1
	fi
}

do_test_group()
{
	test_=$1
	print_line
	print_title_2 "Testing $test_"
	
	folder="$PROJECT_FOLDER/test/$test_"
	if [ ! -d "$folder" ]; then
		print_warning_msg "Can't found test folder"
		return 0
	fi
	
	tput bold
	tput setaf 220
	printf "%-40sTest result\n" "Test name"
	tput sgr0
	tput setaf 221
	printf -- "---------------------------------------------------------------------------------------------\n";

	for d in $folder/*/ ; do
		basename=`basename $d`
		tput bold
		tput setaf 2
		tput setaf 220
		printf "%-40s" "${basename:3}"
		tput sgr0

		script="script.sh"
		cmd="$d$script $FOLDER $d"
		eval $cmd

	
		printf "\n"
	done

}

do_test_sub()
{
	test_=`echo "$1*" | sed "s|/|/*|"`
	print_line
	print_title_2 "Testing $test_"
	
	folder=`find $PROJECT_FOLDER/test/$test_ | sort | head -n 1`
	if [ ! -d "$folder" ]; then
		print_warning_msg "Can't found test folder"
		return 0
	fi
	
	tput bold
	tput setaf 220
	printf "%-40sTest result\n" "Test name"
	tput sgr0
	tput setaf 221
	printf -- "---------------------------------------------------------------------------------------------\n";

	basename=`basename $folder`
	tput bold
	tput setaf 2
	tput setaf 220
	printf "%-40s" "${basename:3}"
	tput sgr0

	script="script.sh"
	cmd="$folder/$script $FOLDER $folder/"
	eval $cmd


	printf "\n"

}



