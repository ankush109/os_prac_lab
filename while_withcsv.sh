
cat test.csv | awk 'NR!=2 {print}' | while IFS="," read id name age
do 
	echo "Id is $id"

#	echo "name is $name"
#	echo "age is $age"
done < test.csv

