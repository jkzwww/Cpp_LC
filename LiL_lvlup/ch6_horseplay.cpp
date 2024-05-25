// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    int max_idx = 8;

    char col_name = knight[0];
    char row_name = knight[1];

    int row = row_name - '0' - 1;
    int col = col_name - 'a';
    
    std::vector<std::pair<int, int>> pos;
    
    // moves h 2 v 1 or v 2 h 1
    int r[] = {-2,-1,1,2};
    int c[] = {-1,1,-2,2,-2,2,-1,1};
    for(int i=0;i<4;i++){
        pos.push_back(std::make_pair(row+r[i], col+c[i*2]));
        pos.push_back(std::make_pair(row+r[i], col+c[i*2 +1]));
    }

    // border check
    for(int j=0; j<pos.size(); ++j){
        
        bool r_check = pos[j].first >= 0 && pos[j].first < max_idx;
        bool c_check = pos[j].second >= 0 && pos[j].second < max_idx;
        // std::cout << pos[j].first << " " << pos[j].second << std::endl;

        if(r_check && c_check){
            std::string move = "xx";
            move[0] = pos[j].first + 1 + '0';
            move[1] = pos[j].second + 'a';
            moves.push_back(move);
            
        }
    }
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}

std::vector<std::string> ref_knight_moves(std::string knight){
    std::vector<std::string> moves;
    int x, y;
    x = knight[0] - 'a' + 1;
    y = knight[1] - '0';
    const int delta1[2] = {-1, 1};
    const int delta2[2] = {-2, 2};
    
    int new_x;
    int new_y;
    std::string new_loc = "  ";

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            new_x = x + delta1[i];
            new_y = y + delta2[j];
            
            if(new_x > 0 && new_x < 9 && new_y > 0 && new_y < 9 ){
                new_loc[0] = new_x + 'a' - 1;
                new_loc[1] = new_y + '0';
                moves.push_back(new_loc);
            }

            new_x = x + delta2[i];
            new_y = y + delta1[j];
            
            if(new_x > 0 && new_x < 9 && new_y > 0 && new_y < 9 ){
                new_loc[0] = new_x + 'a' - 1;
                new_loc[1] = new_y + '0';
                moves.push_back(new_loc);
            }
        }
    return moves;
}