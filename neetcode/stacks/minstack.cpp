
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    vector<pair<int,int>> stack;
    MinStack() {
     ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    }
    
    void push(int val) {
        if(stack.empty()){
            pair<int, int> p;
            p.first = val;
            p.second = val;
            stack.push_back(p);
        }
        else{
            pair<int, int> p;
            p.first = val;
            p.second = min(val,stack.back().second);
            stack.push_back(p);

        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};
