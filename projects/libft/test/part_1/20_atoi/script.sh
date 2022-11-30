#!/bin/bash

folder_source=$1
folder_test=$2

source "$MOULINATOR_FOLDER/sources/test_utils.sh" 

res=`test_compile $folder_source $folder_test./ref.c $folder_source/libft.a`
if [[ $res == 0 ]]; then
	print_no
	exit 
fi

for i in {1..3}; do
	gcc -g -I $folder_source -lbsd $folder_test./test$i.c $folder_source/libft.a -o $folder_test./test$i.bin 
	execute_test $folder_test./test$i.bin $folder_test./test$i.c
done;

#for i in {1..2}; do
#	gcc -g -I $folder_source $folder_test./testmem$i.c $folder_source/libft.a -o $folder_test./testmem$i.bin
#	execute_test_2 $folder_test./testmem$i.bin $folder_test./testmem$i.c
#done;

#for i in {4..5}; do
#	gcc -g -I $folder_source $folder_test./testmem$i.c $folder_source/libft.a -o $folder_test./testmem$i.bin
#	execute_test $folder_test./testmem$i.bin $folder_test./testmem$i.c
#done;

#rm $folder_test./test*.bin
