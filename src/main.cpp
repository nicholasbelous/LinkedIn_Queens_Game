#include "solver.h"
#include "grid.h"
#include <iostream>

int main(){
    std::vector<std::vector<int>> temp_board = {
    {0, 0, 0, 1, 1, 1, 2, 2},
    {0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 1, 3, 3, 3, 2, 2},
    {0, 4, 4, 3, 3, 3, 5, 2},
    {4, 4, 4, 3, 3, 5, 5, 5},
    {4, 4, 6, 6, 5, 5, 5, 5},
    {4, 6, 6, 6, 6, 5, 7, 7},
    {6, 6, 6, 6, 6, 7, 7, 7}
    };

    Grid grid(temp_board);
    Solver solver(grid);

    if(solver.solve(0)){
        std::cout << "Solution Found" << std::endl;
        solver.printSolution();
    } else {
        std::cout << "No Solution Found" << std::endl;
    }


    return 0;
}