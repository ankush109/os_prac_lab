
#arrays 
myarray=( 1 2 3 4 )

echo "${myarray[*]}"
# how to find the number of values in the array 

echo "the length of the array is ${#myarray[*]}"
myarray+=( 4 5 )
echo "${myarray[*]}"
