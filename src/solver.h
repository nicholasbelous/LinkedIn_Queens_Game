#ifndef SOLVER_H
#define SOLVER_H
#include "grid.h"

class Solver {
private: 
    Grid grid;
    int size;

public:
    Solver(Grid g);
    bool solve(int row);
    void printSolution();

};


#endif // SOLVER_H