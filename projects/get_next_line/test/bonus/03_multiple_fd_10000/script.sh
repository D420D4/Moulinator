#!/bin/bash

folder_source=$1
folder_test=$2

source "$MOULINATOR_FOLDER/sources/test_utils.sh" 

compile()
{
	cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=$5 -D FOLDER=\"$2\" -I $1 $1/get_next_line_bonus.c $1/get_next_line_utils_bonus.c $3 -o $4
}

test_compile_2()
{
	res=`cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=1 -D FOLDER=\"$2\" -I $1 $1/get_next_line_bonus.c $1/get_next_line_utils_bonus.c $2 -o /dev/null 2>&1` 
	if [[ $res != "" ]]; then
		echo 0
		echo $res > /tmp/moulinator_test_compile
	else
		echo 1
	fi
}

res=`test_compile_2 $folder_source $folder_test./ref.c`
if [[ $res == 0 ]]; then
	print_no
	exit 
fi

for i in {1..1}; do
	compile $folder_source $folder_test $folder_test./test$i.c $folder_test./test$i.bin 10000 
	execute_test $folder_test./test$i.bin $folder_test./test$i.c 1 
done;

#for i in {2..3}; do
#	gcc -g -I $folder_source -lbsd $folder_test./testmem$i.c $folder_source/libft.a -o $folder_test./testmem$i.bin -lbsd
#	execute_test_2 $folder_test./testmem$i.bin $folder_test./testmem$i.c
#done;

#for i in {1..1}; do
#	gcc -g -I $folder_source -lbsd $folder_test./testmem$i.c $folder_source/libft.a -o $folder_test./testmem$i.bin -lbsd
#	execute_test $folder_test./testmem$i.bin $folder_test./testmem$i.c
#done;

#rm $folder_test./test*.bin
