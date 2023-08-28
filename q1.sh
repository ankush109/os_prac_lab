echo "Enter a number for factorial"
read n
f=1;
if [ $n -lt 0 ]
then 
	echo "Given no. is invalid"
else
	for((i=1;i<=n;i++))
	do
		f=`expr $f \* $i `
	done
	echo "Factorial is : $f "
fi
