# /bin/bash
echo "Enter the no. till which fibonacci should be printed: "
read n
a=0
b=1
i=2
echo "Fibonacci series upto $n""th term : "
if [ $n -eq 0 ] 
then 
	echo "$a"
elif [ $n -eq 1 ]
then
	echo "$a"
	echo "$b"
else 
	echo "$a"
	echo "$b"
	while [ $i -lt $n ]
	do
		f=`expr $a + $b`
		a=$b
		b=$f
		echo $f
		i=`expr $i + 1`
	done
fi



