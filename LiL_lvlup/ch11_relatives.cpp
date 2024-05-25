// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    std::vector<std::string> namelist;
    std::vector<std::string> lastnames;
    std::vector<std::string> newlist;
    // Read the CSV file.
    if(file.is_open()){

        std::string temp,name;
        while(std::getline(file,name,',')){
            std::stringstream ss(name);
            int i=0;
            namelist.push_back(name);
            while(std::getline(ss,temp,' ')){                
                if(i>0) lastnames.push_back(temp);
                i++;
            }
        }
        
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    newlist = lastnames;
   
    //Approach 1 (only find one pair)
    // std::vector<std::string>::iterator finder;
    // finder = std::unique(newlist.begin(),newlist.end());
    // if(finder != newlist.end()){

    //     std::string surname;
    //     int dupIdx = -1;
    //     for(int i{}; i<lastnames.size();i++){
    //         if(lastnames[i]!=newlist[i]){
    //             surname = lastnames[i];
    //             dupIdx = i;
    //             break;
    //         }
    //     }

 
    //     std::vector<std::string>::iterator it;
    //     it = std::find(lastnames.begin(),lastnames.end(),surname);
    //     int firstIdx = std::distance(lastnames.begin(),it);

    //     std::cout << "Relatives found:\n";
    //     std::cout << namelist[firstIdx] << " & " << namelist[dupIdx] << std::endl;

    // }else{
    //     std::cout << "No relatives found.\n\n" << std::flush;    
    // }
    
    //approch 2 (find all pairs)
    std::set<std::string> nameset;
    std::vector<std::string> surname_list;
    std::vector<int> surname_idx;
    for(int i{}; i<lastnames.size();i++){
        if(!nameset.insert(lastnames[i]).second){
            surname_idx.push_back(i);
            surname_list.push_back(lastnames[i]);
        }
    }

    if(!surname_list.empty()){
        std::cout << "Relatives found:\n";
        for(int j{}; j<surname_list.size();j++){
            std::vector<std::string>::iterator finder;
            finder = std::find(lastnames.begin(),lastnames.end(),surname_list[j]);
            int temp_idx = std::distance(lastnames.begin(),finder);
            std::cout << namelist[temp_idx] << " & " << namelist[surname_idx[j]] << std::endl;
        }
    }else{
        std::cout << "No relatives found.\n\n" << std::flush;    
    }

    return 0;
}


void ref_ans(){
    std::vector<std::vector<std::string>> people;
    std::vector<std::string> person;
    std::string entry, name;
    
    std::fstream file ("names.csv", std::ios::in);
    // Get the CSV file into a vector of vectors.
    if(file.is_open()){
        while(std::getline(file, entry,',')){
            std::stringstream str(entry);
            person.clear();
            while(std::getline(str, name,' '))
                person.push_back(name);
            people.push_back(person);
        }
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        
    }
    
    std::cout<<"People found in the CSV file:\n\n";
    
    for(int i=0; i<people.size(); i++){
        for(int j=0; j<people[i].size(); j++)
            std::cout << people[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    for(int i=0; i<people.size()-1; i++){
        for(int j=i+1; j<people.size(); j++)
            if(people[i][1].compare(people[j][1]) == 0){
                std::cout << people[i][0] << " " << people[i][1] << " may be related to " << people[j][0] << " " << people[j][1] << ".\n\n" << std::flush; 
                break;
            }
    }
    std::cout << "No relatives found.\n\n" << std::flush;  

}
 

 