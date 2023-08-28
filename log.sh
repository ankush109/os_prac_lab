#!/bin/bash

# Function to calculate the common logarithm
function compute_logarithm {
    bc -l <<< "scale=2; l($1)/l(10)"
}

# Get the integer from user input
read -p "Enter a positive integer: " N

# Check if the input is a valid positive integer
if ! [[ $N =~ ^[0-9]+$ && $N -gt 0 ]]; then
  echo "Error: Invalid input. Please provide a positive integer."
  exit 1
fi

# Calculate the common logarithm and print the result
result=$(compute_logarithm $N)
echo "The common logarithm of $N is: $result"

