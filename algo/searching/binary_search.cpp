// find, find_if, any_of, for_each

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// sorted in ascending order, return target position 
// O(log n)
int binary_search(vector<int>& nums, int target){
    if(target<nums[0] || target>nums[nums.size()-1]){return -1;}

    int l = 0, r = nums.size()-1;
    int m;

    while(l <= r){
        m = (l+r)/2;
        // m = l + ((r-l)/2); // avoid overflow

        if(nums[m] > target){
            r = m-1;
        }else if(nums[m] < target){
            l = m+1;
        }else{
            return m;
        }
    }

    return -1;
}