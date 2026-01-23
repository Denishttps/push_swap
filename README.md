*This project has been created as part of the 42 curriculum by dbobrov.*

# Push Swap

## Description

**Push Swap** is a sorting algorithm project from the 42 School curriculum.

The goal of the project is to sort a list of integers using two stacks (A and B) and a
restricted set of operations, while minimizing the total number of moves.

The program receives a sequence of integers as input and outputs a list of operations
that will sort the numbers in ascending order in stack A.

## Instructions

### Compilation

```bash
make
```

This command compiles the project and creates the `push_swap` executable.

### Execution

```bash
./push_swap <numbers>
```

Examples:
```bash
./push_swap 4 67 3 87 23
./push_swap "10 9 8 7 6 5 4 3 2 1"
./push_swap -5 10 -3 0 42
```

The program prints the sequence of operations needed to sort the stack.

## Algorithm Overview

- All values are indexed according to their sorted order
- For small stacks (≤ 3 elements), a hardcoded optimal solution is used
- For larger stacks:
  - Elements are pushed to stack B
  - For each element in B, the target position in stack A is calculated
  - The cost of moving each element is evaluated
  - The cheapest element is moved using optimal rotations
  - Combined rotations (`rr` / `rrr`) are used when possible to reduce operation count
- After all elements are moved back, stack A is finalized by rotating the smallest element to the top

## Allowed Operations

- `sa`, `sb`, `ss` — swap the first two elements
- `pa`, `pb` — push the top element between stacks
- `ra`, `rb`, `rr` — rotate stack upwards
- `rra`, `rrb`, `rrr` — rotate stack downwards

## Validation

- Input values are checked for duplicates and integer overflow
- The program exits with an error on invalid input
- Memory usage was verified using `valgrind` (no leaks detected)


## Performance Benchmarks

To validate the project according to 42 School requirements, the following benchmarks apply:

### Maximum Validation (100% + bonus eligibility)
- Sort **100 random numbers** in fewer than **700 operations**
- Sort **500 random numbers** in no more than **5500 operations**

### Minimal Validation (minimum grade: 80%)
Any one of the following combinations is sufficient:
- 100 numbers in under **1100** operations and 500 numbers in under **8500** operations
- 100 numbers in under **700** operations and 500 numbers in under **11500** operations
- 100 numbers in under **1300** operations and 500 numbers in under **5500** operations


## Usage Examples

Count the number of operations:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

Validate the result using the checker:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
```

## Resources

- Push_swap subject (42 Network)
- Turk Algorithm explanation:  
  https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

### AI Usage

AI tools were used **only for clarification and explanation purposes**.
They were consulted to better understand:
- explain me the general idea of cost calculation for stack A
- how combined rotations (`rr` / `rrr`) help reduce the total number of operations
