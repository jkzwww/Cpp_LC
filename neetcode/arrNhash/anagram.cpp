
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


bool isAnagram(string s, string t) {

    if(s.length() != t.length()) return false;

    std::sort(s.begin(),s.end());
    std::sort(t.begin(),t.end());

    for(int i=0;i<s.size();++i){
        if(s[i]!=t[i]) return false;
    }

    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> grouped;
    bool found = false;

    for(auto word:strs){
        for(int i{}; i<grouped.size(); i++){
            if(isAnagram(word,grouped[i][0])){
                grouped[i].push_back(word);
                found = true;
                break;
            }
            cout << "checking " << i << endl;
        }
        
        if(!found){
            vector<string> new_group = {word};
            grouped.push_back(new_group);
        }else{
            found = false;
        }
        
    }

    return grouped;
}

vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    vector<vector<string>> grouped;
    vector<string> sorted_strs = strs;
    vector<string> group_rep;
    bool found = false;

    for(int i{}; i<strs.size(); i++){
        sort(sorted_strs[i].begin(),sorted_strs[i].end());
        found = false;

        for(int j{}; j<group_rep.size(); ++j){
            if(sorted_strs[i]==group_rep[j]){
                grouped[j].push_back(strs[i]);
                found = true;
                break;
            }
        }
        
        if(!found){
            group_rep.push_back(sorted_strs[i]);
            grouped.push_back({strs[i]});
        }

    }

    return grouped;
}

//  std::vector<std::pair<int, int>> vecOfPairs;
vector<vector<string>> groupAnagrams3(vector<string>& strs) {
    vector<vector<string>> grouped;
    vector<string> sorted_strs = strs;
    vector<pair<string,int>> pairstr;
    for(int i{}; i<strs.size(); ++i){
        sort(sorted_strs[i].begin(),sorted_strs[i].end());
        pairstr.push_back(make_pair(sorted_strs[i], i));        
    }
    sort(pairstr.begin(),pairstr.end());

    grouped.push_back({strs[pairstr[0].second]});
    for(int j=1; j<strs.size(); ++j){
        if(pairstr[j].first == pairstr[j-1].first){
            grouped[grouped.size()-1].push_back(strs[pairstr[j].second]);
        }else{
            grouped.push_back({strs[pairstr[j].second]});
        }
    }

    return grouped;
}

// use sorted string as key
// emplace is faster than push back
// take values afterward directly out as array (reduce pushing)
vector<vector<string>> ref_groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> d;
    for (auto& s : strs) {
        string k = s;
        sort(k.begin(), k.end());
        d[k].emplace_back(s);
    }
    vector<vector<string>> ans;
    for (auto& [_, v] : d) ans.emplace_back(v);
    return ans;
}


int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> grouped = groupAnagrams3(strs);

    for(auto group:grouped){
        for(auto word:group){
            cout << word << "   ";
        }
        cout << endl;
    }

    return 0;
}