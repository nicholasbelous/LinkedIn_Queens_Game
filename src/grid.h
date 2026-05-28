#ifndef GRID_H
#define GRID_H
#include <vector>

class Grid {
private: 
    int size;
    std::vector<std::vector<int>> board;
    std::vector<std::vector<bool>> crown;

public:
    Grid(std::vector<std::vector<int>> b, int s);
    Grid(std::vector<std::vector<int>> b);
    std::vector<std::vector<int>> getBoard();

    bool placeCrown(int row, int col);
    bool isValid();
    void print();
    int getSize();
    std::vector<std::vector<bool>> getCrown();
    void removeCrown(int row, int col);
};


#endif //GRID_H