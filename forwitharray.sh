myarray=( 1 2 3 4 5 )

n=${#myarray[*]}

for(( i=0;i<n;i++ ))
do 
	echo " value of array is ${myarray[i]}"
done 

