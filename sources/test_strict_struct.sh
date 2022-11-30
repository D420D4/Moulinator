#!/bin/bash

test_strict_structure()
{
	print_line
	print_title_2 "Testing structure"
	
	ls -1a $PROJECT_FOLDER/structure | sort > /tmp/.outmouli1
	ls -1a $FOLDER | sort > /tmp/.outmouli2

	diff /tmp/.outmouli1 /tmp/.outmouli2 > /tmp/.diffmouli
	res=`cat /tmp/.diffmouli`
	
	print_result $res ""
	printf "\n$res\n"
}
