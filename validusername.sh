#!/bin/bash

if test $# -eq 0
then
	echo "Usage: $(basename $0) username"
	exit
fi

userlist=$(cat /etc/passwd | cut -d ":" -f 1)

for user in $userlist
do
	if test $1 = $user
	then
		echo "$1 is a valid user"
		exit
	fi
done

echo "$1 is an invalid user"
