
echo "Enter a year: "
read y
a=` expr $y % 400 `
b=` expr $y % 4 `
c=` expr $y % 100 `
if [ $a -eq 0 ]
then 
	echo "$y year is a leap year "
elif [ $b -eq 0 ]
then
	echo "$y year is a leap year "
elif [ $c -eq 0 ]
then
	echo "$y year is a leap year "
else
	echo "$y year is not a leap year "
fi
