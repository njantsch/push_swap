# push_swap

## Table of Contents

- [Introduction](#introduction)
- [Objectives](#objectives)
- [Allowed Instructions](#allowed-instructions)
- [Mandatory Part](#mandatory-part)
  - [Rules](#rules)
  - [Algorithm](#algorithm)
  - [Usage push_swap](#usage-push_swap)
- [Bonus Part](#bonus-part)
  - [The "checker" Program](#the-checker-program)
  - [Usage Checker](#usage-checker)

## Introduction

Welcome to the **push_swap** project, a challenging algorithmic endeavor from the coding school **42Heilbronn**. In this project, your task is to sort a set of integer values using two stacks and a set of specific instructions. The goal is to write a C program named `push_swap` that calculates and displays the set of instructions needed to sort the given integers


## Objective

Before diving into the project details, it's important to follow the common instructions provided by **42Heilbronn**:

- Your project must be written in C.
- Follow the Norm guidelines for coding style and structure.
- Your functions should not result in unexpected crashes (except for undefined behaviors).
- Properly manage heap-allocated memory and avoid memory leaks.
- Create a Makefile that compiles your source files to the required output using the flags `-Wall`, `-Wextra`, and `-Werror`.
- Your Makefile should contain at least the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

## Allowed Instructions

The `push_swap` project uses a set of instructions to manipulate the stacks. Here are the available instructions along with their explanations:

- `sa` (swap a): Swap the first two elements at the top of stack a. If there is only one or no elements, this instruction has no effect.
- `sb` (swap b): Swap the first two elements at the top of stack b. If there is only one or no elements, this instruction has no effect.
- `ss`: Execute `sa` and `sb` simultaneously.
- `pa` (push a): Take the first element at the top of stack b and push it onto stack a. If stack b is empty, this instruction has no effect.
- `pb` (push b): Take the first element at the top of stack a and push it onto stack b. If stack a is empty, this instruction has no effect.
- `ra` (rotate a): Shift all elements of stack a up by one position. The first element becomes the last one.
- `rb` (rotate b): Shift all elements of stack b up by one position. The first element becomes the last one.
- `rr`: Execute `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift all elements of stack a down by one position. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift all elements of stack b down by one position. The last element becomes the first one.
- `rrr`: Execute `rra` and `rrb` simultaneously.

## Mandatory Part

### Rules

- We have 2 stacks named `a` and `b`.
- At the beginning:
  - Stack `a` contains a random amount of negative and/or positive numbers without duplicates.
  - Stack `b` is empty.
- The goal is to sort the numbers in ascending order in stack `a`

### The "push_swap" Program

- **Program Name:** `push_swap`
- **Turn In Files:** `Makefile`, `*.h`, `*.c`
- **Makefile:** Contains rules like `NAME`, `all`, `clean`, `fclean`, and `re`.
- **Arguments:** Stack `a` - A list of integers
- **External Functions:** `read`, `write`, `malloc`, `free`, `exit`, and anything YOU coded
- **Description:** Sort stacks

The `push_swap` program must adhere to the following rules:

- Turn in a Makefile that compiles your source files without relinking.
- Avoid using global variables.
- The program must take a list of integers as an argument for stack `a`.
- Display the smallest list of instructions required to sort stack `a`, with the smallest number at the top.
- Instructions must be separated by a newline character.
- Your solution should aim for the lowest possible number of operations. The number of operations will be compared against a limit during evaluation.
- In case of errors (e.g., non-integer arguments, duplicates, etc.), display "Error" followed by a newline on the standard error.

### Algorithm

The core sorting algorithm in the `push_swap` project is a blend of chunking, insertion, and rotation techniques designed to efficiently sort a stack of integers. The main steps of the algorithm can be summarized as follows:

**Chunking Strategy:** Elements in stack `a` are divided into chunks, and a pivot value is dynamically calculated based on the chunk's size. This allows the algorithm to handle different stack sizes effectively.

**Moving Elements to Stack B:** Elements are pushed from stack `a` to stack `b` while maintaining the chunk structure. The algorithm strategically rotates and pushes elements based on their values and the pivot value.

**Pushing Elements Back to Stack A:** After sorting elements in stack `b`, they are pushed back to stack `a`. The algorithm carefully rotates and swaps elements to ensure a smooth transition while maintaining the sorted order.

**Optimal Element Manipulation:** Throughout the process, the algorithm uses helper functions to optimize decisions. For example, the `next_rotate` function calculates optimal rotation directions for efficient pushing and sorting.

**Sorting Small Chunks:** For smaller list of numbers, specialized sorting routines (`sort_three` and `sort_five`) are employed. These routines use specific swap and rotation sequences to efficiently sort the elements.

### Usage push_swap

Compile the program: with `make` or `make all`. Then execute the program `push_swap`
```bash
./push_swap number_to_be_sorted
```
You can also pass a string of numbers as an argument instead of several arguments
```bash
./push_swap "<numbers_to_be_sorted>"
```
The numbers should be delimited by spaces.

After execution you'll get the instructions that were used to sort the numbers delimited by newlines. You can pipe the output into `wc -l` to see how many moves push_swap took to sort the set of numbers.

## Bonus Part

As a bonus, I created a checker program to validate the sorting instructions.

## The "checker" Program

- **Program Name:** `checker`
- **Turn In Files:** `*.h`, `*.c`
- **Makefile:** `bonus`
- **Arguments:** The instructions used to sort the set of numbers
- **External Functions:** same as above

Description:

- It waits and reads instructions from the standard input, each followed by a newline.
- The instructions will be executed on a stack.
- It displays "OK" followed by a newline on the standard output if stack `a` is sorted and stack `b` is empty after executing the instructions.
- It displays "KO" followed by a newline on the standard output in all other cases.

## Usage

To compile the `checker` program, run the following command:
```bash
make bonus
```
If it is done compiling you can just execute the program `checker` like this:
```bash
./checker
```
Then it will wait for input on the `stdin`. You can also pipe the output of the push_swap program into the checker program.
