#pragma once
#include <cassert>

class Board{
    int N;
    int **grid;
public:
    
    Board(int _N) : N(_N){
        grid = new int*[N];
        for(int i = 0; i < N; i++){
            grid[i] = new int[N];
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                grid[i][j] = 0;
    }
    
    ~Board(){
        for(int i = 0; i < N; i++){
            delete [] grid[i];
        }
        delete [] grid;
    }
    
    int& operator() (int x, int y){
        assert(x < N && y < N);
        return grid[x][y];
    }
    
    int getSize(){
        return N;
    }
    
    // function for debugging (kind of dumb, but need to change its
    // signature each time you change the puzzle size...but I suppose
    // in practice we will never need this)
    void setFromArray(int a[4][4]){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                grid[i][j] = a[i][j];
    }
    
    
};

void printPuzzle(Board &b);
bool feasible(Board &b, int row, int col, int val);
bool solve(Board &b, int row, int col);
bool checkPuzzle(Board &b);
int* genPerm(int N);
Board generatePuzzle(int n, int nobs);
