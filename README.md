# LinkedIn Queens Game

This project is a C++ implementation of a solver for the N-Queens problem, where the goal is to place N queens on an N×N chessboard so that no two queens threaten each other (no two queens share the same row, column, or diagonal).

## Features
- Solves the N-Queens problem for any board size
- Efficient backtracking algorithm
- Modular code structure (separate grid and solver logic)
- Command-line interface for custom board input

## How to Build
This project uses CMake for building.

1. Clone the repository and navigate to the project directory.
2. Create a build directory:
	```sh
	mkdir build && cd build
	```
3. Run CMake and build:
	```sh
	cmake ..
	make
	```

## How to Run
After building, run the solver executable:

```sh
./queens-solver
```

You will be prompted to enter the board row by row using numbers for regions. Type `done` when finished.

Example input for a 4x4 board:
```
0 0 1 1
0 0 1 1
2 2 3 3
2 2 3 3
done
```

## Example Output
```
Solution Found!
Q 0 1 1
0 Q 1 1
2 2 Q 3
2 2 3 Q
```