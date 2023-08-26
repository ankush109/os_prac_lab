
# getting values from a file

FILE="/home/ankush/Documents/myscripts/names.txt"
for name in $(cat $FILE)
do 
	echo "name is $name"
done

