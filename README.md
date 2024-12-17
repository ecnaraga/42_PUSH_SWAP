# 42_PUSH_SWAP

Goal
    - Mandatory : Write and adapt a sorting algorythm minimizing the number of operations to sort a stack of int, using 2 stacks maximum
    - Bonus : Write a checker program that takes the same stack than above and apply the operations realized to check if the stack is sorted at the end of the push_swap program

Launch

    - Compile with the makefile
    - To sort a list of int : launch in a terminal ./push_swap <arg0> <arg1> <arg2> ...

    - To control with the checker, launch in a terminal ARG="list of int" && ./push_swap $ARG | ./checker $ARG 

Authorized moves

    - swap : swap the first two elements in one of the two stacks
    - push : push the first element of one stack in the other one
    - rotate : shift up all elements of a stack by one 
    - reverse rotate : shift down all elements of a stack by one

Authorized functions

    - read, write, malloc, free, exit
    - megalibft

What is forbidden

    - Function lseek
    - Global variables
    - for
    - do ... while
    - switch
    - case
    - goto
    - Ternary operators
    - Variable-size tables

The project must be written in accordance with the 42's Norm
