Submission by -
Tanishk Goyal
Roll number: 2020141

General Make Instructions - 
To make all the files in the assignment, use the "make" command in bash.
To make a specific file, use make < file name > for eg. make Q3

Question 1 - 
The solution to both parts of this question is given in the file "Q1.c". 
To run the solution, use the command "./Q1 < s1 > < s2 > < s3 > < s4 > < s5 > < s6 >
where s1 ... s6 are the user specified number of columns in row 1 to 6 respectively.
On running the programme the output will be given in the form of two 2-D arrays, filled with random numbers from 1 to 9.
The first array will be the solution of the a part with hardcoded rows of the length - {7,4,6,3,7,2}

The second array will give the resized array depending upon the user input.
Note: the number of rows will always remain 6, only the number of columns in each row can be changed.

Question 2 - 
Question 2 has been divided into 4 files:
Q2a.c - Implementation of a singly linked list
Q2b.c - Implementation of a doubly linked list
Q2c_stack.c - Implemenation of a stack
Q2c_queue.c - Implementation of a queue

After making the object files, you can run these files using "./Q2a", "./Q2b", "./Q2c_stack", "./Q2c_queue" to get the corresponding outputs.
All of these programmes have a console menu where you can iteratively insert, delete, search , print etc.


Question 3 - 
The solution to this question is stored in the file "Q3.c", this file takes command line input.
After running make, run the command "./Q3 < function > < operand 1 > < operand 2>"
where the functions can be - 
add - addition
sub - subtraction
mul - multiplication
divi - division
expo - exponentiation

Kindly note that the function for division is "divi" and not "div", similarly for exponentiation function is "expo" and not "exp".

Note: The operands have to be integers

Question 5 -
After running make,
To run this program use the command "./Q5 < num 1 > < num 2 > ... < num  n >"
this program takes the array to be sorted as command line arguments, each new element is space seperated.
For example to sort an array [ 2, 4, 2, 5], you can run the command "./Q4 2 4 2 5"

After that you will get the option to choose either bubble or selection sort, in the console. After this choice, the sorted array will be printed.

