// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>
#include <vector>

// game_status()
// return the total counts of marks on grid for each possible winning patttern
std::vector<std::vector<int>> game_status(char game[][3]){
    
    std::vector<std::vector<int>> status( 3 , std::vector<int> (8,0));  ;
    // r1,r2,r3,c1,c2,c3,d1,d2
    int player = 0;
    for(int r{}; r<3; r++){
        for(int c{};c<3;c++){
            if(game[r][c] != ' '){
                player = 0;
                if(game[r][c] == 'O'){
                    player = 1;
                }
                status[player][r]++;
                status[player][3+c]++;

                if(r==c){status[player][6]++;}
                
                if(r==2-c){status[player][7]++;}
            }
        }
    }

    for(int i{};i<8;i++){
        status[2][i] = status[0][i] + status[1][i]; 
    }

    return status;
}

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

// #define TWO_PLAYERS
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    std::vector<std::vector<int>> stat = game_status(game);    
    int AI_mark = (mark == 'O');
    int player_mark = 1-AI_mark;
    int r,c;
    int win_stat = -1; // winning pattern to be in attention
    bool chance = true; // chance to win or block 
    for(int i{}; i<8; i++){ //prioritise winning if possible
        if(stat[AI_mark][i] == 2 && stat[2][i]<3){
            win_stat = i;
            break;
        }
    }
    if(win_stat < 0){ // try to block opponent
        for(int i{}; i<8; i++){
            if(stat[player_mark][i] == 2 && stat[2][i]<3){
                win_stat = i;
                break;
            }else if(i==7){
                chance = false;
            }
        }
    }

    int ai_row = -1;
    int ai_col = -1;
    
    std::cout << "chance to win/block: " << win_stat << std::endl;

    if(chance){
        std::cout << "YES chance" << std::endl; 
        if(win_stat<3 && stat[2][win_stat]<3){
            ai_row = win_stat;
            std::cout << "ROW set" << std::endl; 
        }else if(win_stat<6 && stat[2][win_stat]<3){
            ai_col = win_stat-3;
            std::cout << "COL set" << std::endl; 
        }else if(win_stat==6){
            for(int j{}; j<3; j++){
                if(game[j][j] == ' '){
                    ai_row = j;
                    ai_col = j;
                    break;
                }
            }
        }else{
            for(int j{}; j<3; j++){
                if(game[j][2-j] == ' '){
                    ai_row = j;
                    ai_col = j;
                    break;
                }
            }
        }
    }

    if(ai_row < 0 && ai_col >= 0){
        do{
            ai_row++;
        }while(game[ai_row][ai_col] != ' ');
        std::cout << "random ROW" << std::endl;
    } else if(ai_row >= 0 && ai_col < 0){
        do{
            ai_col++;
        }while(game[ai_row][ai_col] != ' ');
        std::cout << "random COL" << std::endl;
    }else{
        do{
            ai_row = std::rand() % 3;
            ai_col = std::rand() % 3;
        }while(game[ai_row][ai_col] != ' ');
        std::cout << "random BOTH" << std::endl;
    }
    
    game[ai_row][ai_col] = mark;

    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]){

    // Write your code here
    std::vector<std::vector<int>> stat = game_status(game);    
    int fill_count = 0;
    for(int i{}; i<8; i++){
        if(stat[0][i] == 3){
            std::cout << "player win state: " << i << std::endl;
            return 'X';
        }else if(stat[1][i] == 3){
            std::cout << "AI win state: " << i << std::endl;
            return 'O';
        }

        if(i<6 && stat[2][i]==3){
            fill_count++;
        }
    }

    if(fill_count>2)
        return 't';

    return 'a';
}




// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
