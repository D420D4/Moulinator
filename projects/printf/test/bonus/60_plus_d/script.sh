#!/bin/bash

folder_source=$1
folder_test=$2

source "$MOULINATOR_FOLDER/sources/test_utils.sh" 
for i in {1..2}; do
	
	res=`test_compile $folder_source $folder_test./ref.c $folder_source/libftprintf.a`
	if [[ $res == 0 ]]; then
		print_no
		exit 
	fi

	gcc -g -D FUNCTION=printf $folder_test./test$i.c $folder_source/libftprintf.a -o $folder_test./test$i.bin 2>/dev/null 
	execute_valgrind $folder_test./test$i.bin > $folder_test./out_ref
	gcc -g -D FUNCTION=ft_printf $folder_test./test$i.c $folder_source/libftprintf.a -o $folder_test./test$i.bin 2>/dev/null
	execute_valgrind $folder_test./test$i.bin > $folder_test./out_ft

	eval_diff "$folder_test./out_ref" "$folder_test./out_ft"
done;

