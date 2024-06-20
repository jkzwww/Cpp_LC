#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
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
        // freq used as index row, numsbers recorded as arrays
        bucketCount[i->second].push_back(i->first); //vector account for similar freq values
    }

    for (int i = nums.size(); i >= 0; i--) { //higher freq = nums.size
        if (results.size() >= k) {
            break;
        }
        if (!bucketCount[i].empty()) {
            results.insert(results.end(), bucketCount[i].begin(), bucketCount[i].end());
        }
    }
    return results;
}
