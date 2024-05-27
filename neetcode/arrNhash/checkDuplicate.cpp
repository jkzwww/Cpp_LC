
#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool containsDuplicate1(vector<int>& nums) {
    std::set<int> numset;
    bool dup_found = false;
    sort(nums.begin(),nums.end());
    for (int no:nums) {
        // if unique set insertion fail
        if (!numset.insert(no).second){
            dup_found = true;
            break;
        }
    }

    return dup_found;
}

bool containsDuplicate(vector<int>& nums) {

    // untie cincout, even faster
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unordered_map<int,int> nummap;

    // speed of short >> int!
    for(short i{}; i<nums.size(); ++i){
        if(nummap[nums[i]] != 0) return true; // use return earlier
        nummap[nums[i]]++;
    }

    return false;
}

int main(){
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};

    std::cout << "Contains duplicate? " << containsDuplicate(nums);
}