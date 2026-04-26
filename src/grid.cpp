#include "grid.h"
#include <vector>
#include <iostream>
#include <algorithm>

Grid::Grid(std::vector<std::vector<int>> b, int s) : board(b), size(s) {
    crown = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
}

Grid::Grid(std::vector<std::vector<int>> b) : board(b), size(b.size()) {
    crown = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
}

bool Grid::placeCrown(int row, int col) {
    std::vector<std::vector<bool>> tempCrowns = crown;

    crown[row][col] = true;

    if(isValid()) {
        return true;
    }

    crown = tempCrowns;
    return false;
}

bool Grid::isValid() {
    // check each region has exactly one crown
    std::vector<int> regionCount(size, 0);

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(crown[row][col]){
                int region = board[row][col];
                regionCount[region]++;
                if(regionCount[region] > 1) return false;
            }
        }
    }

    //Checks that each row, col, and surrounding squares has no queen
    std::vector<int> qLoc(size, -1);
    for(int row = 0; row < size; row++) {
        int trueCount = 0;
        for(int col = 0; col < size; col++) {
            if(crown[row][col]) {
                trueCount++;
                qLoc[row] = col;
            }
        }
        if(trueCount > 1) return false;
    }
    for(int q = 0; q < size; q++) {
        if(qLoc[q] != -1) {
            if(q == 0) {
                if(std::abs(qLoc[0] - qLoc[1]) <= 1) return false;
            }
            else if(q == size-1) {
                if(std::abs(qLoc[q] - qLoc[q-1]) <= 1) return false;
            }
            else {
                if(std::abs(qLoc[q] - qLoc[q-1]) <= 1) return false;
                if(std::abs(qLoc[q] - qLoc[q+1]) <= 1) return false;
            }
        }
    }
    return true;
}

void Grid::print() {
    for(int col = 0; col < size; col++) {
        for(int row = 0; row < size; row++) {
            std::cout << board[col][row];
        }
        std::cout << std::endl;
    }
}

int Grid::getSize(){
    return size;
}

void Grid::removeCrown(int row, int col){
    crown[row][col] = false;
}