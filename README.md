# Push-Swap Project

## Introduction

This repository hosts the Push-Swap project, an assignment from the 42 school curriculum focused on algorithmic design and complexity. The goal of Push-Swap is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. Through the development of two programs, `push_swap` and `checker`, this project challenges students to explore sorting algorithms and optimize their solutions for efficiency.

## Features

- Efficient sorting algorithm to sort numbers with a limited set of operations.
- `push_swap` program that calculates and displays the necessary operations to sort the numbers.
- `checker` program that takes the operations from `push_swap` and applies them to ensure they correctly sort the stack.
- Performance optimization to minimize the number of operations used for sorting.

## Dependencies

Push-Swap is written in C and depends on the following to run:

- GCC or Clang compiler
- Make (for compiling)
- Standard C libraries

## Installation

To compile the Push-Swap project, please follow these steps:

1. Clone the repository to your local machine:

```bash
git clone git@github.com:akhellad/push_swap.git
```

2. Navigate to the cloned directory:

```bash
cd push-swap
```

3. Compile the project:

```bash
make
```

This will compile both `push_swap` and `checker` programs.

## Usage

After compiling the project, you can run `push_swap` and the bonus `checker` program as follows:

- To use `push_swap` to sort numbers and output the operations:

```bash
./push_swap [list of numbers]
```

This will output a list of operations that `push_swap` has determined will sort the provided numbers.

- **Bonus:** The `checker` program, which I developed as an additional feature, verifies if the list of operations sorts the stack correctly:

```bash
echo [operations] | ./checker [same list of numbers]
```

Replace `[list of numbers]` with the numbers you wish to sort, and `[operations]` with the operations output by `push_swap`. This bonus program `checker` allows you to manually test the efficiency and accuracy of the sorting instructions generated by `push_swap`.

## Example

```bash
./push_swap 2 1 3 6 5 8
sa
ra
pb
ra
pa
```

```bash
echo "sa ra pb ra pa" | ./checker 2 1 3 6 5 8
OK
```

The inclusion of the `checker` program as a bonus demonstrates my initiative to enhance the project's interactivity and user experience, allowing for an immediate validation of the `push_swap` output.

## Credits

This project was developed by Ahmed Khelladi, a student at Ecole 42. The Push-Swap project is a testament to the efficiency and optimization challenges in algorithmic thinking and computer science fundamentals.

