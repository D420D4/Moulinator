#!/bin/bash

shopt -s extglob

#export MOULINATOR_FOLDER="$HOME/Brouillons/Moulinator"
export MOULINATOR_FOLDER="/tmp/Moulinator"


source "$MOULINATOR_FOLDER/sources/display.sh"

rm /tmp/mouli_trace

print_line
print_title
print_line
if [ ! -d $MOULINATOR_FOLDER ]; then
	print_error_msg "Moulinator folder not found. [$MOULINATOR_FOLDER]"
	exit -1
fi

source "$MOULINATOR_FOLDER/sources/test_makefile.sh"
source "$MOULINATOR_FOLDER/sources/test_plagiat.sh"
source "$MOULINATOR_FOLDER/sources/test_no_folder.sh"
source "$MOULINATOR_FOLDER/sources/test_norminette.sh"
source "$MOULINATOR_FOLDER/sources/test_strict_struct.sh"
source "$MOULINATOR_FOLDER/sources/do_test.sh"
source "$MOULINATOR_FOLDER/sources/analyse_date.sh"
source "$MOULINATOR_FOLDER/sources/make_watch.sh"
source "$MOULINATOR_FOLDER/sources/runner.sh"


folder=`pwd`
project=`basename $folder`
project_folder="$MOULINATOR_FOLDER/projects/$project"

export FOLDER=$folder
export PROJECT_FOLDER=$project_folder

print_text_inline "Current folder" $folder
print_text_inline "Project" $project
print_text_inline "test folder" $project_folder
print_text_inline "subject" "$project_folder/$project.pdf"

if [ ! -d $project_folder ]; then
	print_error_msg "test folder not found. [$project_folder]"
	exit -1
fi

rules_file="$project_folder/rules"
if [ ! -f $rules_file ]; then
	print_error_msg "rules file not found. [$rules_file]"
	exit -1
fi

export MAX_SCORE=0
export SCORE=0
export CAN_BE_BETTER=0

if [[ $1 == "" ]]; then
	while IFS= read -r line; do
		if [[ $line == set_rule:* ]]; then
			rule=${line:9}
			if [[ $rule == "all_flags" ]]; then
				export ALL_FLAGS=1
			elif [[ $rule == "NO_LIBTOOL" ]]; then
				export NO_LIBTOOL=1
			fi

		elif [[ $line == do_test_makefile:* ]]; then
			makefile_test "$folder/${line:17}"
		elif [[ $line == do_test_plagiat:* ]]; then
			files=`echo "${line:16}" | sed "s|[^ ]* *|${folder}/&|g"`
			test_plagiat "$files"
		elif [[ $line == do_analyse_date:* ]]; then
			files=`echo "${line:16}" | sed "s|[^ ]* *|${folder}/&|g"`
			analyse_date "$files"
		elif [[ $line == do_test_norminette:* ]]; then
			files=`echo "${line:19}" | sed "s|[^ ]* *|${folder}/&|g"`
			test_norminette "$files"
		elif [[ $line == do_make_watch ]]; then
			make_watch
		elif [[ $line == do_test_check_no_folder ]]; then
			test_no_folder
		elif [[ $line == do_test_strict_structure ]]; then
			test_strict_structure
		elif [[ $line == do_test:* ]]; then
			test_=${line:8}
			do_test "$test_"
		fi
	done < $rules_file
else
	do_test $1
fi

#print_score
rm .out .errout 2> /dev/null
