# Lab-06: Standard Input/Output Functions and Standard Input/Output Streams

## Name: 

## Honor Code:

I, Rakesh Ravula, declare that I have completed this assignment completely and entirely on my own, without any unathorized consultation from others or unathorized access to online websites. I have read the UAB Academic Honor Code and understand that any breach of the UAB Academic Honor Code may result in severe penalties.

Student Signature/Initials: Rakesh Ravula

Date: 03/01/2023

## Assignment:

1. Write a program in C to read the *Listings.csv* file.

2. Declare a function, sortByHostName, that should sort the data based on hostname.
 
3. Declare a function, sortByPrice, that should sort the data based on price.

4. After sorting, sortByPrice and sortByHostName should write the sorted array to a file.



**General Approach**

1. Declare a struct called 'Listing' with contains all the attributes found in *'Listings.csv'*.

2. Define a function that will take one line of the CSV file and return a 'Listing' struct with corresponding attribute values.

3. Declare an array of the 'Listing' structs.

4. Open the *'Listings.csv'* file with the *fopen()* function in read-mode.

5. Loop through each line of the *'Listings.csv'* file. Feel free to use either the *fgets()* function or the *getline()* function.

6. For each line, call the function you previously defined.

7. Store the result in array of 'Listing' structs.

8. In sortByHostName and sortByPrice, use the qsort() function to sort the array.

9. Use the *fopen()* to open a file in write mode.

10. Use the *fputs()* function or the *fprintf()* to write the sorted array to a file.
