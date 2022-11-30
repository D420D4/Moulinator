check_flags()
{
	
	while read line
	do
		tput setaf 14
		printf "$line\n"

		if [[ `echo $line | grep gcc | wc -l` == 1 ]]; then
			if [[ `echo "$line" | grep -- "-g "| wc -l` == 1 ]]; then
				print_warning_msg "Flag -g found"	
			fi
			if [[ $ALL_FLAGS == 1 ]]; then

				if [[ `echo "$line" | grep -- "-Wall "| wc -l` == 0 ]]; then
					print_error_msg "Flag -Wall not found"	
				fi
				if [[ `echo "$line" | grep -- "-Werror "| wc -l` == 0 ]]; then
					print_error_msg "Flag -Werror not found"	
				fi
				if [[ `echo "$line" | grep -- "-Wextra "| wc -l` == 0 ]]; then
					print_error_msg "Flag -Wextra not found"	
				fi
			fi
		fi

		if [[ `echo $line | grep -E "^libtool" | wc -l` == 1 ]]; then
			if [[ $NO_LIBTOOL == 1 ]]; then
				print_error_msg "libtool used :("	
			fi	
		fi
	done < "${1:-/dev/stdin}"
}

	make_watch()
	{
		print_line
		print_title_2 "Make"
		make re | check_flags
	}
