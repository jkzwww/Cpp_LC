#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(){

    stack<string> burger;
    stack<string> vgburger;
    vector<string> ingredients = {"bun","veggie","patty","cheese","bun"};

    // check empty
    if(burger.empty()){
        cout << "empty stack!" << endl;
    }

    // push elem
    for(auto& m:ingredients){
        cout << "inserted: "  << m << endl;
        burger.push(m);

        if(m == "bun"){
            vgburger.push("veggie");
        }else{
            vgburger.push(m);
        }
    }

    // emplace elem (no copy constructor called, to consturctor)
    vgburger.emplace("sauce");

    // get size
    cout << "\nstack size: " << burger.size() << endl;
    
    // peak / get top of stack
    string top_stack = burger.top();
    cout << "top of stack: " << burger.top() << endl;

    // pop top
    burger.pop();
    cout << top_stack << " removed\n";

    // swap stacks
    vgburger.swap(burger);
    cout << "Swapped to VG.\n";
   

    return 0;
    
}