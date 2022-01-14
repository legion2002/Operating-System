Question 1 - 

The solution to this file is saved in the file "Q1.sh".
Instructions to run ( In a linux terminal ) - 
1) If you are running the file for the first time, you might also have to run "chmod u+x Q1.sh"
2) run the command "./Q1.sh < date >" in the terminal
3) The date should be of the format "dd-mm-yy"

The program validates the date on its own, if you have entered the correct date it will show the correct month in the calendar format.
If you have entered the wrong date, you will receive "The date is invalid" error.

Question 2 -

The solution to this file is saved in the file "Q2.sh"

Instructions to run ( In a linux terminal ) - 
1) If you are running the file for the first time, you might also have to run "chmod u+x Q2.sh"
2) run the command "./Q2.sh < function > < operand 1 > < operand 2> ... < operand n > " in the terminal
3) The "function" command can only be of the form - add, sub, mul , div or exp.
4) The operands should all be integers, there can be any number of operands >= 2.

The program performs the necessary computations according to standard arithmetic rules and returns the correct output.
Note: Divisions return the answer according to standard integer division
Note: The exponentiation operation follows a left to right approach, i.e it is computed after every new operand is entered.
For eg. the input 2 3 4 will give the output (2^3)^4. So kindly enter the input accordingly.

for Question 3 and 4 - 
run the make command to obtain the executable files for Q3a, Q3b and Q4
to compile a single file, run make "filename"

Question 3 -
The solution to this question has been divided into 2 files, Q3a and Q3b.
Q3a is the implementation of a simple binary search tree, to run this file enter the command "./Q3a" after running the make file.

Q3b is the implementation of a height balanced binary search tree ( AVL tree), to run this file enter the command "./Q3b" after running the make file.

On running these commands, you will see a menu where you can iteratively insert, delete, or print the preorder traversal to see the current state of the tree.

Question 4 -
To run this program use the command "./Q4 < num 1 > < num 2 > ... < num  n >"
this program takes the array to be sorted as command line arguments, each new element is space seperated.
For example to sort an array [ 2, 3, 4, 5], you can run the command "./Q4 2 3 4 5"

After that you will get the option to choose either bubble or selection sort, in the console. After this choice, the sorted array will be printed.

