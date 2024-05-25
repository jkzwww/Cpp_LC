#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void testFunc(int n)
{
    int player = 0;
    int winner = 0;
    int move = 0;
    int stones = n;
    bool p_move[3]{};
    int moveset[] = {2,3,5};
    vector<vector<int>> sum_matrix = {
        {4,5,7},{5,6,8},{7,8,10}
    };
    vector<int>::iterator iter;

    while(stones>0){

        if(stones > 20){
            move = 0;
        }else if(stones < 7){
            winner = player;
            break;
        }
        else{
            move = 0;
            for(int i{}; i<3; i++){
                int stones_left = stones-moveset[i];
                if(std::find(sum_matrix[i].begin(),sum_matrix[i].end(),stones_left) != sum_matrix[i].end()){
                    move++;
                }
                else{
                    move = i;
                    break;
                }
            }
        }

        cout << "move : " << move << endl;
        player = (player+1)%2;
        if(move>2){
            winner = player;
            break;
        }
        else{
            stones -= moveset[move];
        }
    }

    cout << "stones : " << stones << endl;
    cout << "winner is player " << winner+1 << endl;
}

string findWinner(int n){
    vector<int> moveset = {2, 3, 5};
    vector<bool> dp(n+1,false);

    dp[0] = false;
    dp[1] = false;

    for(int stones=2; stones<=n; stones++){
        for(int move:moveset){
            if(stones-move >= 0 && !dp[stones-move]){
                dp[stones] = true;
                break;
            }
        }
    }
    return (dp[n]) ? "First":"Second";
    
}

int main(){

    cout << findWinner(8);

    return 0;
}