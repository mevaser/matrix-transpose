
# Matrix Transpose with Pthreads

This project demonstrates how to use multithreading with Pthreads in C to transpose a matrix.

## Features
- Generates a random `RAWS x COLS` matrix with values between 1 and `RANGE_UP`.
- Uses multithreading with Pthreads to transpose the matrix.
- Prints both the original matrix and the transposed matrix.

## Requirements
To compile and run this program, you'll need:
- GCC or any C compiler with Pthreads support.
- Linux, macOS, or Windows with MinGW/WSL.

## How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/matrix-transpose.git
   cd matrix-transpose
   ```

2. Compile the program:
   ```bash
   gcc -pthread -o transpose transpose.c
   ```

3. Run the program:
   ```bash
   ./transpose
   ```

## Example Output
Below is an example of what the program output looks like:

```
Original Matrix:
12 5 8 14 19
1 6 4 2 17
11 3 9 10 13

Transposed Matrix:
12 1 11
5 6 3
8 4 9
14 2 10
19 17 13
```

## Credits
Developed by [Mevaser Zehoray](https://github.com/your-username).

---

## License
This project is licensed under the MIT License. You are free to use, modify, and distribute this code.
