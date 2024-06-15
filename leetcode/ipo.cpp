#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <queue>

using namespace std;

// k : max projects
// w : initial capital

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    
    int cap = w;
    vector<pair<int,int>> projects; // capital-profit pair
    priority_queue<int> maxheap; // access to max profit project

    for(int i{}; i<profits.size(); i++){
        projects.push_back({capital[i],profits[i]});
    }

    sort(projects.begin(),projects.end());

    int i{};
    for(int j{}; j<k; j++){
        
        while(i < projects.size() && projects[i].first <= cap){
            // push possible profits with current capital
            maxheap.push(projects[i].second);
            ++i;
        } 

        // check possible projects
        if(maxheap.empty()){ break;}

        //select maximum profit project
        cap += maxheap.top();
        maxheap.pop(); // pop the project done
    }

    return cap;

}

int main(){

    return 0;
}