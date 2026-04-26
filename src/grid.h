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

    bool placeCrown(int row, int col);
    bool isValid();
    void print();
    int getSize();
    void removeCrown(int row, int col);
};


#endif //GRID_H