#include "solver.h"
#include "grid.h"
#include <iostream>

Solver::Solver(Grid g) : grid(g) {
    size = g.getSize();
}

bool Solver::solve(int row){
    if(row == size) return true;

    for(int col = 0; col < size; col++){
        if(grid.placeCrown(row, col)) {
            if(solve(row+1)) return true; // Recursing to next row
            grid.removeCrown(row,col); // Else if doesn't work try for next row
        }
    }

    return false;
}

void Solver::printSolution() {
    std::vector<std::vector<bool>> crownBoard = grid.getCrown();
    std::vector<std::vector<int>> board = grid.getBoard();
    
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            if(crownBoard[row][col]) {
                std::cout << "Q ";
            } else {
                std::cout << board[row][col] << " ";
            }
        }
        std::cout << std::endl;
    }
}
