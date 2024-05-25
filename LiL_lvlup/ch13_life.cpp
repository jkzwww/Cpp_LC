// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
void run_game(char game[N][M],int lives[N][M]) {
    
    int neighbour;
    char live = 'X';
    char dead = '-';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            neighbour = lives[i][j];

            if(neighbour==3 && game[i][j]==dead){
                game[i][j] = live;
            }else if(neighbour<2 || neighbour>3){
                game[i][j] = dead;
            }
            
        }
    }
    
}


void update_lives(char game[N][M],int lives[N][M]) {
    
    int row1,row2,row3,col;
    bool alive = 0;
    int op[3] = {-1,0,1};

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            
            alive = (game[i][j] == 'X');
            if(alive){
                for(int k=0; k<3; k++){
                
                    row1 = (i-1)%N;
                    row2 = i;
                    row3 = (i+1)%N;
                    col = (j+op[k])%M;

                    lives[row1][col]++;
                    lives[row2][col]++;
                    lives[row3][col]++;
                }
                lives[i][j]--;
            }
        }
    }
    
}

// ver with 3 full loops
void new_update_lives(char game[N][M], int lives[N][M]) {
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (game[i][j] == 'X') {
                for (int d = 0; d < 8; d++) {
                    int ni = (i + dr[d] + N) % N;
                    int nj = (j + dc[d] + M) % M;
                    lives[ni][nj]++;
                }
                lives[i][j]--;
            }
        }
    }
}

int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    
    std::memset(game,'-',N*M); // Initialize game with dashes.
    char new_game[N][M];
    int new_lives[N][M];

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";
        int lives[N][M]{};
        std::memcpy(new_game,game,N*M);
        
        update_lives(new_game,lives);
        run_game(new_game,lives);
        
        std::memcpy(game,new_game,N*M);

        // for (auto &row : lives){
        //     for (auto &no : row)
        //         std::cout << " " << no;
        //     std::cout << "\n";
        // }
        // std::cout << "\n";

        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}

// int main() {
//     std::string go_on;
//     do {
//         std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
//         std::getline(std::cin, go_on);
//     } while (go_on != "Exit");

//     return 0;
// }


