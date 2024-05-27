#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <list>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<int> topK;
    vector<pair<int,int>> intpair;
    unordered_map<int,int> freqmap;

    for(auto& i : nums){
        freqmap[i]++;
    }

    for(auto& [key,value] : freqmap){
        intpair.emplace_back(make_pair(value,key));
    }

    sort(intpair.begin(),intpair.end());

    for(int j{}; j<k; ++j){
        topK.emplace_back(intpair[intpair.size()-1-j].second);
    }

    return topK;
}

// hashmap for freq
// 2d array based on nums size
// direct refer based on freq as index
vector<int> ref_topKFrequent(vector<int>& nums, int k) {
    vector<vector<int>> bucketCount(nums.size() + 1);
    unordered_map<int, int> countMap;
    vector<int> results;
    for (int i = 0; i < nums.size(); i++) {
        countMap[nums[i]]++;
    }
    for (auto i = countMap.begin(); i != countMap.end(); i++) {
        // value used as index, key used as value
        bucketCount[i->second].push_back(i->first);
    }
    for (int i = nums.size(); i >= 0; i--) {
        if (results.size() >= k) {
            break;
        }
        if (!bucketCount[i].empty()) {
            results.insert(results.end(), bucketCount[i].begin(), bucketCount[i].end());
        }
    }
    return results;
}

int main(){

    int k=3;
    vector<int> nums = {1,1,1,2,2,3};

    vector<int> mytop = topKFrequent(nums,k);
    for(auto& i:mytop) cout << i << endl;

    return 0;
}