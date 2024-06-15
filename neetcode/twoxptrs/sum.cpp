#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

// too slow!
vector<int> twoSum(vector<int>& numbers, int target) {
    
    vector<int> ans;
    int temp;
    vector<int>::iterator iter;
    for(int i{}; i<numbers.size(); ++i){
        temp = target-numbers[i];
        iter = find(numbers.begin()+1+i, numbers.end(), temp);

        if(iter!=numbers.end()){
            ans.emplace_back(i+1);
            int found_idx = std::distance(numbers.begin(), iter);
            ans.emplace_back(found_idx+1);
            break;
        }
    }
    
    return ans;
}

vector<int> twoSum2(vector<int>& numbers, int target) {
    std::unordered_map<int, int> num_map; // to store the number and its index
    std::vector<int> ans;

    for (int i = 0; i < numbers.size(); ++i) {
        int complement = target - numbers[i];

        // check if the complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            // if found, return the indices +1 (1-based index)
            ans.push_back(num_map[complement] + 1);
            ans.push_back(i + 1);
            return ans;
        }

        // store the index of the current number
        num_map[numbers[i]] = i;
    }

    return ans; // return empty if no solution found
}

vector<int> twoSum3(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    vector<int> res;
    while(left < right) {
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
            res.push_back(left+1    );
            res.push_back(right+1);
            return res;
        }
        // since input is sorted
        if(sum > target) {
            --right;
        } else {
            ++left;
        }
    }
    return res;
}


vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ans;
    set<vector<int>> s;
    int left,right,mid;
    int sum;

    sort(nums.begin(),nums.end());

    for(int i=0; i<nums.size(); i++){ // find all possible set for left(i) (i+1 to end)

        left = i;
        mid = i+1;
        right = nums.size()-1;

        while(mid<right){
            // cout << "left: " << nums[left] << endl;
            // cout << "mid: " << nums[mid] << endl;
            // cout << "right: " << nums[right] << endl;

            sum = nums[left]+nums[right]+nums[mid];
            // cout << "the sum: " << sum << "\n\n\n";
            if(sum>0){ // too large
                right--;
            }else if(sum<0){ // too small
                mid++;
            }else{
                s.insert({nums[left], nums[mid], nums[right]}); // check unique combi
                // for further combi within current right&left
                // outside range combo alr tested
                right--;
                mid++;
            }
        }

    }   

    for(auto triplet : s)
        ans.push_back(triplet);
    return ans;

}

// neetcode
vector<vector<int>> threeSum3(vector<int>& nums) {
    vector<vector<int>> res;
    int l,r,sum;

    sort(nums.begin(),nums.end());

    for(int i{}; i<nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1])   continue; // avoid duplicate triplets

        l = i+1;
        r = nums.size()-1;

        while(l<r){
            sum = nums[i] + nums[l] + nums[r];
            // similar to 2 sum
            if(sum>0){ r--;}
            else if(sum<0){ l++;}
            else{
                res.push_back({nums[i],nums[l],nums[r]});
                l++; //start from next l combi
                while(nums[l]==nums[l-1] && l<r){ l++;} //skip similar number
            }
        }
    }
    return res;
}

int main(){

    // vector<int>  nums = {-1,0,1,2,-1,-4};
    
    // vector<int>  nums = {0,0,0};
    // vector<int> nums = {1,2,-2,-1};
    // vector<int> nums = {-2,0,1,1,2};
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

    vector<vector<int>> sum3 = threeSum3(nums);

    for(auto& ans:sum3){
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    return 0;
}