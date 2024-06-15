#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// sum of range [i,j] of nums = sum[j]-sum[i-1]
vector<int> prefix_sum(vector<int> nums){

    vector<int> sum = nums;
    for (int i=1; i<nums.size(); i++){
        sum[i] += sum[i-1];
    }

    return sum;
}

/*
It is always about the in between intuition through prefix sum,
eg. if sum[j]-sum[i] = k -> sum[j] = sum[i]+k / sump[j-k] = sum[i]
*/


// prefix sum with hashmap
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp.insert({0, 1}); //account for initial subarray[i=0,j] = k
    for (int it : nums) {
        sum += it; // prefix
        count += mp[sum - k]; //prefix_sum(Y)= prefix_sum(X) + k -> subarray(i_X,j_y) = k
        mp[sum]++; 
    }
    return count;
}


// if sum[i] mod k = x and sum[j] mod k = x, then sum of range[i,j] mod k = 0
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    int sum = 0;
    int rem = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; //handle subarray that starts from beginning where mod=0 (initial count)
    for (int i : nums) {
        sum += i;
        rem = sum%k;
        // sum = (sum + i) % k;
        if (rem < 0)
            rem += k; // ADD k if sum negative to make it positive
        count += mp[rem]; // count previous occurence of similar remainder 
        mp[rem]++;
    }
    return count;
}


// max length with same 1 and 0s
// same as finding max length of array where sum=0 (turn all 0 to -1)
int findMaxLength(vector<int>& nums) {
    int sum{};
    int count{};
    int res{};
    unordered_map<int,int> mp;
    mp[0] = -1; //account for initial case [1,0]
    for(int i=0; i<nums.size(); i++){
        if(nums[i]){
            count++;
        }else{
            count--;
        }

        if(mp.count(count)){ // if prev count similar to current count, valid subarray
            int l = i-mp[count];
            res = max(l,res);
        }else{
            mp[count] = i; // use index for length
        }
        
    }
    return res;
}

int findMaxLengthSumK(vector<int>& nums,int k){
    int sum{};
    int res{};
    unordered_map<int,int> mp;
    mp[0] = -1;

    for(int i{}; i<nums.size(); ++i){
        sum += nums[i];

        if(mp.count(sum-k)){
            res = max(res, i-mp[sum-k]);
        }else{
            mp[sum] = i;
        }
    }

    return res;
}




int main(){

    vector<int>nums = {1,5,3,4,6,8};

    nums = prefix_sum(nums);

    // for(auto& no:nums){
    //     cout << no << endl;
    // }

    int x,y;
    cout << "insert range for sum: " ;
    cin >> x >> y;
    
    if(x>0){
        cout << "the sum between range [" << x << " , " << y <<"] : " << nums[y]-nums[x-1] << endl;
    }else{
        cout << "the sum between range [" << x << " , " << y <<"] : " << nums[y] << endl;
    }
    
}