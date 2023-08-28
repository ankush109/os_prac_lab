sum=0
for i in $@
do
	for((j=1;j<=$i;j++))
	do
		((sum+=j))
	done
	echo "Sum of $i naturals numbers: "$sum
	sum=0
done
