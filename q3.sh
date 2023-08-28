
echo "Enter the no. whose sum is to be calculated: "
read n
s=0
if [[ $n =~ ^[0-9]+$ ]];
then
	while [ $n -gt 0 ]
	do
		d=` expr $n % 10 `
		s=` expr $s + $d `
		n=` expr $n / 10 `
	done
	echo "Sum is $s"
else
	echo "Invalid input "
fi
