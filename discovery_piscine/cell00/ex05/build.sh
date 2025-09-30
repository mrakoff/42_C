#/bin/bash
if [ $# -eq 0 ]; then
	echo "No argument supplied"
	exit 1
	fi
for var in "$@"
do
	mkdir "ex$var"
done
