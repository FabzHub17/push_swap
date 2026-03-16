*This project has been created as part of the 42 curriculum by tvithara.*

# 🔀 Push Swap

A sorting algorithm project in C: sort a stack of integers using only a limited set of operations, with the fewest moves possible.

---

## Description

Push Swap is a 42 school project that challenges you to sort a list of integers using two stacks — **stack a** and **stack b** — and a restricted set of operations.

The program takes a list of integers as arguments (representing the initial state of stack a) and outputs the shortest sequence of instructions needed to sort them in ascending order.

The hard part isn't sorting — any sorting is easy. The hard part is sorting it *efficiently*, with as few operations as possible. The evaluation benchmarks you against strict operation limits.

**Stack operations available:**

| Instruction | Description |
|-------------|-------------|
| `sa` / `sb` | Swap the top 2 elements of stack a / b |
| `ss` | `sa` and `sb` at the same time |
| `pa` / `pb` | Push top of b to a / Push top of a to b |
| `ra` / `rb` | Rotate stack a/b upward (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | Reverse rotate a/b (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

**Performance benchmarks (for 100% grade):**
- Sort 100 numbers in fewer than **700 operations**
- Sort 500 numbers in fewer than **5500 operations**

---

## Instructions

### Compilation

```bash
make
```

This compiles the `push_swap` executable.

```bash
make clean    # remove object files
make fclean   # remove object files + executable
make re       # recompile from scratch
```

### Usage

```bash
./push_swap [list of integers]
```

**Example:**
```bash
./push_swap 4 67 3 87 23
```

Output (sequence of instructions printed to stdout):
```
pb
pb
sa
pa
pa
ra
```

**Check if the output is valid** using the provided checker:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
# Output: OK or KO
```

**Count how many operations were used:**
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

### Error handling

The program prints `Error` to stderr and exits in these cases:
- A non-integer argument is passed
- A number exceeds `INT_MAX` or `INT_MIN`
- Duplicate numbers are present

```bash
./push_swap 0 one 2 3
# Error
```

---

## Project Structure

```
push_swap/
├── includes/       # Header files
├── libft/          # Custom C library
├── src/            # Source files
└── Makefile
```

---

## Technical Choices

### Algorithm: Turk Algorithm

The sorting strategy used in this project is the **Turk Algorithm**, an optimized greedy insertion sort designed specifically for the push_swap constraints.

**How it works:**

1. **Index normalization** — Before anything else, all numbers are replaced by their relative rank (e.g. `[42, -3, 100]` becomes `[1, 0, 2]`). This makes comparisons simpler and position calculations easier.

2. **Push everything to b** — All elements except the top 3 are pushed from stack a to stack b. While pushing, elements are kept in a rough descending order in b (largest on top, smallest on bottom), using `pb` + occasional `sb`/`rb`.

3. **Greedy insertion back to a** — For each element in b, the algorithm calculates the **cheapest cost** to insert it into its correct position in a. Cost = rotations needed in a + rotations needed in b. It always picks the element in b with the lowest total cost, combining `rr`/`rrr` when possible to move both stacks simultaneously.

4. **Final rotation** — Once all elements are back in a, a final rotation brings the smallest element to the top.

**Why Turk?** Because it's fast enough to hit the 700 ops limit on 100 numbers and 5500 ops on 500 numbers (the 100% benchmark), while being conceptually cleaner than radix sort for this specific set of allowed operations.

---

## Resources

### Documentation & References
- [Sorting algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Stack data structure — GeeksForGeeks](https://www.geeksforgeeks.org/stack-data-structure/)
- [Big O Notation explained](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/)
- [Push Swap — The least amount of moves with two stacks (Medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer)

### AI Usage

Claude (claude.ai) was used during this project for the following:
- Understanding how different sorting algorithms adapt to the stack constraint (only push/rotate, no random access)
- Getting explanations of algorithm complexity and why certain approaches perform better within the operation limits
- Generating this README

All code was written, understood, and reviewed by the author. AI was used as a learning and explanation tool, not as a code generator.
