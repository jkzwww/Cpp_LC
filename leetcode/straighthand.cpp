
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    
    if(hand.size()%groupSize != 0){ return false;}

    bool res;
    int stack=0;
    vector<int> cards = hand;
    sort(cards.begin(),cards.end());

    int temp = -1, i = 0, card=cards[i];
    while(!cards.empty()){
        // cout<< "i: " << i;
        if(temp<0){
            temp = card;
            cout << "\n\nnew stack: " << card;
            cards.erase(cards.begin()+i);
            stack++;
            i = 0;
        }else if(stack==groupSize){
            stack = 0;
            temp = -1;
            cout << "\nstack complete!\n";
            for(auto c:cards){
                cout << c;
            }
            i = 0;
        }else if(card==(temp+stack)){
            cout << card << "  ";
            cards.erase(cards.begin()+i);
            stack++;
            i = 0;
        }else{
            i++;
            // cout << "skip card: " << card << endl;
            if(i>cards.size()-1){break;}
        }
        card = cards[i];
    }
      
    

    if(cards.empty() && stack==groupSize){return true;}

    return false;
}

bool isNStraightHand2(vector<int>& hand, int groupSize) {

    if(hand.size() % groupSize != 0) return false;

    map<int, int> hsh;

    for(auto val: hand){
        hsh[val]++;
    }

    while(!hsh.empty()){
        int minVal = hsh.begin()->first;
        for(int i = 0; i < groupSize; i++){
            int currentVal = minVal + i;
            if(hsh.find(currentVal) == hsh.end()) return false;
            if(hsh[currentVal] == 1) hsh.erase(currentVal);
            else hsh[currentVal]--;
        }
    }
    return true;
}

int main(){

    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    cout << "\n\n\n" << isNStraightHand(hand,3);

    return 0;
}