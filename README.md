# push_swap: sorting with two stacks

Sorts a list of integers using **two stacks** and a limited set of operations, while printing as
few operations as possible. A classic 42-network algorithm project.

## Operations
`sa` `sb` `ss` (swap) · `pa` `pb` (push) · `ra` `rb` `rr` (rotate) · `rra` `rrb` `rrr` (reverse rotate)

## Algorithm
- **2 to 5 numbers:** hand-optimised sorts (at most a few moves)
- **More than 5:** values are **indexed** (replaced by their rank), then sorted with a
  **binary radix sort** across the two stacks
- Input validation: non-numbers, duplicates and integer overflow print `Error`

## Build and run
```bash
make
./push_swap 3 2 5 1 4
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG   # OK
```

**Stack:** C · algorithms · linked lists
