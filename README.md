# Student Grade Calculator in C

A beginner-friendly C program that calculates a student's grade based on input marks (0 to 100) using a `switch` statement.

## Grade Criteria

| Marks Range | Grade |
| ----------- | ----- |
| 90 – 100    | A     |
| 80 – 89     | B     |
| 70 – 79     | C     |
| 60 – 69     | D     |
| 40 – 59     | E     |
| Below 40    | Fail  |

---

## How the Program Works

1. **Input Collection**:
   - The program uses `fgets()` to read the student's name safely including spaces.
   - It reads integer marks using `scanf()`.

2. **Input Validation**:
   - Before evaluating grades, the program verifies if the marks fall within the valid range `0` to `100`.
   - If marks are less than `0` or greater than `100` (or if non-integer input is provided), an error message is printed and execution stops.

3. **Grade Evaluation (`switch` Statement)**:
   - Standard `switch` statements match against exact discrete values (e.g., integers), not ranges like `90..100`.
   - To use a `switch` statement effectively with numerical ranges, we divide the integer marks by `10` (`marks / 10`):
     - Marks `100` $\rightarrow$ `10`
     - Marks `90` to `99` $\rightarrow$ `9`
     - Marks `80` to `89` $\rightarrow$ `8`
     - Marks `70` to `79` $\rightarrow$ `7`
     - Marks `60` to `69` $\rightarrow$ `6`
     - Marks `50` to `59` $\rightarrow$ `5`
     - Marks `40` to `49` $\rightarrow$ `4`
     - Marks `0` to `39` $\rightarrow$ `3`, `2`, `1`, `0`
   - Grouping `case` labels (e.g., `case 10:` fallthrough to `case 9:`) allows handling multiple quotient values for the same grade.

4. **Output Display**:
   - Displays formatted results showing the student's name, marks, and calculated grade.

---

## How to Compile and Run

### Prerequisites
- GCC or any standard C compiler installed.

### Compilation
Open a terminal in the program directory and compile using GCC:

```bash
gcc -Wall -Wextra -std=c99 grade_calculator.c -o grade_calculator
```

### Execution
Run the compiled binary:

```bash
./grade_calculator
```

### Example Output

```
Enter student's name: Alice Smith
Enter marks (0 - 100): 85

========================================
            STUDENT RESULT
========================================
Name  : Alice Smith
Marks : 85 / 100
Grade : B
========================================
```
