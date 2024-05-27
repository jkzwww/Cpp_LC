//Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string encode(vector<string>& strs) {
    
    string coded;
    for(auto& s : strs){
        coded += to_string(s.length()) + s;
    }

    return coded;
}

vector<string> decode(string s) {

    vector<string> decoded;
    int i{},length;
    string temp;

    while(i<s.length()){
        temp = "";
        length = s[i]- '0';
        for(int j=1; j<=length; j++){
            temp += s[i+j];
        }
        decoded.push_back(temp);
        i += (length+1);
    }

    return decoded;
   
}

int main(){

    vector<string> input = {"we","say",":","yes"};

    string encoded = encode(input);

    vector<string> output = decode(encoded);

    for(auto& str:output){
        cout << str << endl;
    }
    
    return 0;
}