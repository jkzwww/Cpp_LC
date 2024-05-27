
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    
    if(nums.empty()) return 0;

    int answer=1;
    int new_answer=1;
    bool new_flag=false;

    sort(nums.begin(),nums.end());

    for(int i=1; i<nums.size(); ++i){

        cout << "\nnumber now:" << nums[i] <<endl;
        

        if(nums[i]==nums[i-1]){
            continue;
        }else if(nums[i] != nums[i-1]+1){
            
            if(nums.size()-1-i<answer){break;}

            if(new_flag){
                    new_answer=1;
            }else{
                cout << "new round!\n";
                new_flag = true;
                new_answer = 1;
            }
            
        }else{

            if(new_flag){   new_answer++;}
            else{   answer++;};
            
        }

        if(new_answer>answer){
            answer  = new_answer;
            new_flag = false;
        }

        cout << "answer: " << answer << endl;
        cout << "new answer: " << new_answer << endl;
    }


    return answer;
}


int ref_longestConsecutive(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxi=INT_MIN; // constant of minimum val of int
    int cnt=1;
    sort(nums.begin(),nums.end());

    if(nums.size()<=1){ // return size for 0/1
        return nums.size();
    }

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]-1){ //forward compare
            cnt++;
            maxi=max(cnt,maxi); //max count kept track
        }
        else if(nums[i]==nums[i+1]){
            continue;
        }
        else{
            cnt=1;
        }
    }

    return maxi==INT_MIN?1:maxi;
    
}

int main(){

    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6,11,12,13,14,15,16,17,18,19,20};

    cout << "Longest consecutive numbers: " << longestConsecutive(nums) << endl;

    return 0;
}