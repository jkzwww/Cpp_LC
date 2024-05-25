#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//writing file
bool writefile(string filename,string content) 
{
    ofstream fid (filename,std::ios_base::app);
    if (fid.is_open()) {
        fid << '\n';
        fid << content;
        fid.close();
        return true;
    }
    else{
        cout << "Unable to open file";
        return false;
    }
}

//reading file 
vector<string> readfile(string filename)
{   
    vector<string> paragraph;
    string line;
    ifstream fid (filename);

    if (fid.is_open() ) //check
    {
        while ( getline (fid,line))
        {
            cout << line << '\n';
            paragraph.push_back(line);
        }
        fid.close();
    }
    else{
        cout << "Unable to open file";
    } 
    return paragraph;
}

void writeCSV(string filename)
{
    fstream fid;
    fid.open(filename, ios::out | ios::app);

    int n;
    cout << "Enter number of datapoints: ";
    cin >> n;
    cout << "Enter the id number and name for " << n << "data :";

    int id;
    string name;
    for(int i{};i<n;i++){
        cin >> id
            >> name;
        
        fid << id << "," 
             << name << "\n";
    }
    
}

std::vector<std::pair<int, string>> readCSV(string filename)
{
    fstream fid;

    fid.open(filename,ios::in);

    std::vector<std::pair<int, string>> datapoints;
    // vecOfPairs.push_back(std::make_pair(1, 10));

    vector<string>row;
    string line,word,temp;

    while(fid >> temp){
        row.clear();

        getline(fid,line);
        
        std::stringstream s(line);
        while(getline(s,word,',')){
            row.push_back(word);
        }

        int data_id = stoi(row[0]);
        string data_str = row[1];
        datapoints.push_back(std::make_pair(data_id, data_str));
    }   

    return datapoints;
}       

int main() 
{
    string filename = "sampletext.txt";
    readfile(filename);

    string new_item = "strawberry";
    writefile(filename,new_item); 
    return 0;
}



