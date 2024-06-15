
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


string replaceWords(vector<string>& dictionary, string sentence) {
    
    unordered_map<char,vector<string>> wordmap;
    vector<string> words;
    string res;

    for(auto& root:dictionary){
        wordmap[root[0]].push_back(root);
    }

    size_t startPos = 0;
    size_t endPos = 0;
    char delimiter = ' ';

    while((endPos = sentence.find(delimiter,startPos)) != std::string::npos){
        words.push_back(sentence.substr(startPos,endPos-startPos));
        startPos = endPos + 1;
    }
    words.push_back(sentence.substr(startPos));

    for(int i{}; i<words.size(); i++){
        // cout << word << endl;
        string word = words[i];
        for(int j{};j<word.length()+1;j++){
            
            if(wordmap.count(word[0])==0){break;}
            string newword = word.substr(0,j);

            vector<string>::iterator it = find(wordmap[word[0]].begin(),wordmap[word[0]].end(),newword);
            if(it!=wordmap[word[0]].end()){
                word = *it;
                // cout << *it << endl;
                break;
                
            }
            // cout << newword << endl;
        }
        if(i == 0){
            res.append(word);
        }else{
            res.append(" ");
            res.append(word);
        }
    }



    cout << res;

    return res;
}


int main(){

    vector<string>dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    
    replaceWords(dictionary,sentence);

    return 0;
}