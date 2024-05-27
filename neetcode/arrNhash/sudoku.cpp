
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char,short> rowmap[9];
    unordered_map<char,short> colmap[9];
    unordered_map<char,short> gridmap[9];   
    char x;
    int grid;

    for(short i{}; i<9; ++i){
        for(short j{}; j<9; ++j){

            x = board[i][j]; 

            if(x == '.'){ continue;}

            grid = 3*(i/3) + (j/3);

            if(rowmap[i][x] != 0 || colmap[j][x] != 0 || gridmap[grid][x] != 0) return false;

            rowmap[i][x]++;
            colmap[j][x]++;
            gridmap[grid][x]++;
        
        }
    }

    return true;
}

bool isValidSudoku2(vector<vector<char>>& board) {
    unordered_map<char,short> sudokumap[3][9]{}; 
    char x;
    int grid;

    for(short i{}; i<9; ++i){
        for(short j{}; j<9; ++j){

            x = board[i][j]; 

            if(x == '.'){ continue;}

            grid = 3*(i/3) + (j/3);

            if(sudokumap[0][i][x]|| sudokumap[1][j][x]|| sudokumap[2][grid][x]) return false;

            sudokumap[0][i][x]=sudokumap[1][j][x]=sudokumap[2][grid][x]=1;

        }
    }

    return true;
}

int main(){

    vector<vector<char>> board = 
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};

    cout << "The sudoku is valid ? " << isValidSudoku2(board) ;

    return 0;
}


            // if(rowmap[i][x] != 0){
            //     cout << "row " << i << " invalid!\n";
            // }else if(colmap[j][x] != 0){
            //     cout << "col " << j << " invalid!\n";
            // }else if(gridmap[grid][x] != 0){
            //     cout << "grid " << grid << " invalid!\n";
            // }