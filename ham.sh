 #!/bin/bash

# Create a student file (Students.dat) containing four fields, Name, Roll, Phone and Address. The field separator is ,
echo "John,123,4567,XYZ" > Students.dat
echo "Doe,456,7890,ABC" >> Students.dat
echo "Smith,789,0123,DEF" >> Students.dat

# Function to print the menu
print_menu() {
echo "Select an option:"
echo "1. Sort the records in reverse order of Roll number and store the output in a new file (Sorted.dat)"
echo "2. Replace lower case letters with the upper case letters in the file 'Sorted.dat'. Take file input using redirection."
echo "3. Write commands to find out the records with unique name in the file 'Sorted.dat. Append the output records to Students.dat."
echo "4. Display only the 2nd and 3rd lines from the above file (Students.dat)."
echo "5. Exit"
}

print_menu

# Get the user's choice
echo -e "Enter your choice: "
read choice

# Do the corresponding task based on the user's choice
case $choice in
	1) sort -n -r Students.dat > Sorted.dat
echo "Records sorted successfully!";;
# Sort the records in reverse order of Roll number and store the output in a new file (Sorted.dat)
	2) tr '[:lower:]' '[:upper:]' < Sorted.dat > Sorted_upper.dat
echo "Lower case letters replaced with upper case letters successfully!";;
# Replace lower case letters with the upper case letters in the file 'Sorted.dat". Take file input using redirection.
	3) uniq Sorted_upper.dat >> Students.dat
echo "Unique records appended to Students.dat successfully!";;
# Write commands to find out the records with unique name in the file 'Sorted.dat. Append the output records to Students.dat.
	4)	head -n 2 Students.dat;;
# Display only the 2nd and 3rd lines from the above file (Students.dat).
	5) echo "Exiting..."
exit 0;;
	*) echo "Invalid choice!";;
esac
