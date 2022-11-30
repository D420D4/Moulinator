#!/bin/bash

folder_source=$1
folder_test=$2

source "$MOULINATOR_FOLDER/sources/test_utils.sh" 

res=`test_compile $folder_source $folder_test./ref.c $folder_source/libft.a`
if [[ $res == 0 ]]; then
	print_no
	exit 
fi

for i in {1..1}; do
	gcc -g -I $folder_source $folder_test./test$i.c $folder_source/libft.a -o $folder_test./test$i.bin
	execute_test $folder_test./test$i.bin $folder_test./test$i.c
done;

rm $folder_test./test*.bin
