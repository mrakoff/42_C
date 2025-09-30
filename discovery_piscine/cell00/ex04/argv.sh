#/bin/bash
a=0
for var in "$@"
do
	echo "$var"
	a=`expr $a + 1`
	if [ $a == 3 ]
    then
        break
    fi
done

