run_s()
{
	cmd="$MOULINATOR_FOLDER$1"
	eval $cmd > .out 2>.errout
}

run_s1()
{
	cmd="$MOULINATOR_FOLDER$1"
	eval $cmd 
}
