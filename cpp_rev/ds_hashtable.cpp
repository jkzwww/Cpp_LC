/*
Hash Tables
- key-value look-up
- key(string/int) -> hash function -> hashcode(integer) -> index(array) 
- table size not based on hashcode possibilities(but actual data)
- potential similar hashcode, or even similar index(collision)
- chaining(linked list to resolve collision, store key as well)

*/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class HashTable{
    private:
        static const int hashGroups = 10;
        //#hashgroups of linked lists (separate chaining)
        list<pair<int,string>> table[hashGroups]; 

    public:
        bool isEmpty() const; //(const)does not modify any member 
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i<hashGroups; i++){
        sum += table[i].size();

        if(sum){ return false;}
    }

    return true;
}   

// return index of table(must be within hashgroups)
int HashTable::hashFunction(int key){
    return key%hashGroups;
}

void HashTable::insertItem(int key,string value){
    int hashCode = hashFunction(key);
    auto& cell = table[hashCode];

    bool keyExists = false;
    auto bItr = begin(cell);
    for(;bItr != end(cell);bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists.Value replaced.\n";
            break;
        }
    }

    if(!keyExists){
        //constructs the object in-place at the end of the vector
        cell.emplace_back(key,value); 
        cout << "[INFO] Pair inserted.\n";
    }

    return;
}

void HashTable::removeItem(int key){
    int hashCode = hashFunction(key);
    auto& cell = table[hashCode];

    bool keyExists = false;
    auto bItr = begin(cell);
    for(;bItr != end(cell);bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Pair removed.\n";
            break;
        }
    }

    if(!keyExists){
        cout << "[WARNING] Key not found.\n";
    }

    return;
}

void HashTable::printTable(){
    for(int i{}; i<hashGroups; i++){
        if(table[i].size() == 0) continue;

        for(auto& pair: table[i]){
            cout << "[INFO] Key: " << pair.first << " Value: " << pair.second << endl;
        }
    }
    
    return;
}


int main(){

    HashTable HTmenu;

    if(HTmenu.isEmpty()) cout << "Empty Menu!\n";
    
    HTmenu.insertItem(100, "cold brew");
    HTmenu.insertItem(101, "americano");
    HTmenu.insertItem(102, "espresso");
    HTmenu.insertItem(103, "cappucino");
    HTmenu.insertItem(104, "mocha");
    HTmenu.insertItem(105, "latte");
    HTmenu.insertItem(106, "caramel macchiato");
    HTmenu.insertItem(107, "matcha latte");
    HTmenu.insertItem(108, "maple latte");
    HTmenu.insertItem(109, "strawberry shortcake");
    HTmenu.insertItem(110, "canele");
    
    cout << "~~~~~~Current menu~~~~~~\n";
    HTmenu.printTable();

    if(HTmenu.isEmpty()) cout << "[ERROR] Menu empty.\n";

    cout << "[INFO] Spring season new items!\n";
    HTmenu.insertItem(111,"strawberry matcha latte");
    HTmenu.removeItem(108);

    cout << "~~~~~~New menu~~~~~~\n";
    HTmenu.printTable();

    return 0;
}