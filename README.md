*This project has been created as part of the 42 curriculum by jstrasse*

Push_swap | 42 Lausanne 
made by Jefferson Strasser (jstrasse@student.42lausanne.ch)


<ins>**Description**</ins>

What is Push_swap ? And what is the goal of this project ?

Push_swap is a program that sorts integer number in order. It handles arguments between INT_MIN and INT_MAX which are found in the limits.h header. Any other arguments or double arguments will prompt an Error. 
This project consists of coding an algorithm that sorts an arbitrary number of integers in the minimum of operations possible. I have 2 stacks at my disposal to do it. The operations allowed are to rotate and reverse rotate one or both stacks, to push from one stack to another or both at the same time, and to swap two numbers at the top of a stack or both stacks at the same time.
For minimal project validation, I have to sort 100 numbers in under 1100 operations and 500 numbers in under 8500 operations. For maximum validation, I have to sort 100 random numbers in fewer than 700 operations and 500 numbers in no more than 5500 operations. I have not done the bonus part of his project which consist on creating my own checker for the push_swap program.

<ins>**Instructions**</ins>

To compile the program you have to open a terminal in the folder and make. This will create the ./push_swap program which you can use to sort numbers. You can use ./push_swap with different arguments or with a single string containing the numbers to sort. The program initializes the stack depending on how you input your numbers.

<ins>**Resources**</ins>

My first resource was a medium page that explains the project (https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
I spent time trying to sort the numbers like they did in that page but faced a challenge as I wanted to use my libft list functions and not recreate them. So I created a new datatype t_stack in order to add numbers and index in a linked list. I then added this datatype to a t_list in order to use my libft functions. I also had to make sure my makefile compiles the libft with the bonus part.   

I used AI to explain how radix sort works with linked list. I had already looked at this site (https://www.geeksforgeeks.org/dsa/radix-sort/) but they explain it with arrays instead of linked list. 
This showed me that I couldn't sort the numbers with their digit size but had to add an index and sort the index by bits. I had to add a function to find the smallest number and assign its index. Then when all numbers had its index assigned I sort the index by bits to sort the stack. 

<ins>**Difficulties**</ins>

The main difficulty I encountered in this project was the radix sort part of the algorithm. I tried differents ways to sort my numbers until I decided to sort by bits instead of digit size or index. This was the only way for me to make it work with linked list and libft functions. 



Thank you for reading I hope you enjoy my work/code. Cheers ! Jefferson 