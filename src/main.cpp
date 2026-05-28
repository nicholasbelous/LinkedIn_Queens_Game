#include "solver.h"
#include "grid.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::vector<int>> parseBoard(std::vector<std::string> rows) {
    std::vector<std::vector<int>> board;
    for(auto& row : rows) {
        std::vector<int> boardRow;
        std::istringstream ss(row);
        int val;
        while(ss >> val) {
            boardRow.push_back(val);
        }
        board.push_back(boardRow);
    }
    return board;
}

int main(){
    std::cout << "Enter the board row by row using numbers for regions." << std::endl;
    std::cout << "Type 'done' when finished." << std::endl;
    std::cout << "Example row: 0 0 1 1 2 2 3 3" << std::endl << std::endl;

    std::vector<std::string> rows;
    std::string line;

    while(true) {
        std::cout << "Row " << rows.size() + 1 << ": ";
        std::getline(std::cin, line);
        if(line == "done") break;
        if(!line.empty()) rows.push_back(line);
    }

    if(rows.empty()) {
        std::cout << "No board entered." << std::endl;
        return 1;
    }

    Grid grid(parseBoard(rows));
    Solver solver(grid);

    std::cout << std::endl << "Solving..." << std::endl << std::endl;

    if(solver.solve(0)){
        std::cout << "Solution Found!" << std::endl << std::endl;
        solver.printSolution();
    } else {
        std::cout << "No Solution Found." << std::endl;
    }

    return 0;
}