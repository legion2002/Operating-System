Submission by -
Tanishk Goyal
Roll number: 2020141

General Make Instructions - 
To make all the files in the assignment, use the "make" command in bash.
To make a specific file, use make < file name > for eg. make Q3

Question 1 - 
The solution to both parts of this question is given in the file "Q1.c". 
To run the solution, use the command "./Q1 < input file name > < output file name >

Note: The input and output files should both be in the same folder as that of Q1.c
Once both files are in the same folder you can run a command like - ./Q1 input.txt output.txt (if the file names are input and output)

On running this command the content from input.txt will be transferred to output.txt

Question 2 - 
To run Q2, use the command ./Q2 < number to be converted >
The number will be converted to a base of 256 and then stored in the character array finalPos
The output on the console may not make sense as the number has been converted to a character array. You can look at the code, and check the value of the final array to see that the number is stored correctly.
The convert function of the code converts the normal integers which are stored as characters to base 256, by long dividing with 256 and then storing the mod in reverse order. ( Just like a standard binary conversion )
Kindly debug the code in VSCode to see in detail how the code is working.

Question 3 - 
After running make, run ./Q3 
The solution to this programme is based on menu driven console input, follow the menu prompts to input whether you want to swap variables or arrays, and then enter the respective values.

Question 4 - 
After running make, run ./Q4
A menu will prompt you to enter the string that you want to reverse. After you input the string the programme will reverse the string and output it on the console.

Question 5 -
After running make, run ./Q5
The menu will prompt you to enter the number of integers in the input array. After which you will be prompted to enter all the numbers one by one.
At the end of the input you can enter the number you want to search in the array, the programme will sort the input array and display the index at which the number is present.
If the number is not present in the array, the programme will return "NOT FOUND"

