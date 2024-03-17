#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void string_event()
{

    // get input as cstring (char array)
    char name[256];
    cout << "Please enter your name: ";
    cin.getline(name, 256, '\n');

    // cstring <-> string
    string namestring = name;
    cout << namestring.c_str();

    // string comparison function
    char s1[25] = "momo";
    char s2[] = "mikan";
    int result = strcmp(s1, s2); // 0:equal,neg:s1<s2,pos:s1>s2

    // string concatenation
    strcat_s(s1, s2); // s1 has to be large enough for s2

    // string copy(replace)
    strcpy_s(s1, s2);

    // string length
    size_t strlen(const char *s1); // size_t:int that cant be negative
    int length = strlen(s1);       // not size,size is 25,this is 4

    // create substring
    string myStr = "karappo";
    int rPos = myStr.find("r");
    if (rPos != string::npos)
    {
        string myNewStr = myStr.substr(0, rPos); 
    }
    std::transform(myStr.begin(), myStr.end(), myStr.begin(), toupper);
}

void vector_event()
{

    vector<int> vMarks; // no size,dynamic

    // modify
    // access vector
    vMarks[0] = 85;
    vMarks.push_back(75); // next spot available
    //vMarks.pop_front(); // delete from head
    vMarks.pop_back();    // delete last thing(return)

    // memory
    vMarks.resize(3);   // set the size manually
    vMarks.reserve(10); // reserve size similar as array
    vMarks.clear();     // clears vector

    vMarks.size();     // check size (elements num)
    vMarks.capacity(); // amount of memory allocated(might > elements)
    vMarks.empty();    // check whether empty
}

// vector as function argument
void displayInventory(vector<string> inv)
{
    for (unsigned int item = 0; item < inv.size(); item++)
    {
        cout << inv[item] << "\n";
    }
}

// iterator
void iterator_event()
{
    // classname<param>::iterator name
    vector<int>::iterator iter; // declare iterator for a vector of int
    vector<int> vMarks = {20, 80, 70, 65, 43};

    for (iter = vMarks.begin(); iter != vMarks.end(); iter++)
    {
        cout << *iter << " "; // print the element where iter is
    }

    // used to insert things and will move everything in place
    vMarks.insert(vMarks.begin() + 1, 90);
    vMarks.erase(vMarks.begin(), vMarks.begin() + 2);

    // find item
    vector<int>::iterator finder_iter;
    finder_iter = find(vMarks.begin(), vMarks.end(), 72);

    if (finder_iter != vMarks.end()) // iterm found
    {
        int finder_idx = std::distance(vMarks.begin(), finder_iter);

        cout << "Item found : " << *finder_iter << "\n";
        cout << "Position : " << finder_idx << "\n";

        vMarks.erase(finder_iter);
        cout << "Item erased.\n"
             << std::endl;
    }
    else
    {
        cout << *iter << "not found!" << std::endl;
    }

    // string vector
    vector<string> vNames;
    vNames.push_back("John");
    vNames.push_back("Jenn");

    vector<string>::iterator name_iter;
    for (name_iter = vNames.begin(); name_iter != vNames.end(); name_iter++)
    {
        // similar to (*name_iter.size)
        cout << name_iter->size() << " ";
    }
}

void extra_it_ops()
{

    vector<int> vMarks = {20, 80, 70, 65, 43};
    vector<int> sqMarks;

    // algo
    //std::random_shuffle(vMarks.begin(), vMarks.end());
    std::sort(vMarks.begin(), vMarks.end());

    //Function transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);
    // back_inserter(vect) output iterator which uses push_back (automatic resize)
    std::transform(vMarks.begin(),vMarks.end(),std::back_inserter(sqMarks),[](int mark){return mark*mark;});

    //Function for_each(InputIterator first, InputIterator last, Function f);
    std::for_each(vMarks.begin(),vMarks.end(),[](int &mark){ mark += 10;});
    auto print_elem = [](int elem){ cout << elem << "\t";};
    std::for_each(vMarks.begin(),vMarks.end(),print_elem);



}

/* iterators: begin() , end()
capacity: size() , length() , clear() , empty()
modifier: append(), insert() , erase() , replace()
operator: find() , substr() */

 
// Function for demonstration 
void replaceDemo(string s1, string s2, string s3, string s4) 
{ 
    // Using positions 
    cout << "Using positions:"
         << "\n"; 
    // Replaces 7 characters from 0th index by s2 
    s1.replace(0, 7, s2); 
    cout << s1 << endl; 
  
    // Replaces 5 characters from 6th index of s4 with 
    // 5 characters from 0th of s3 
    s4.replace(6, 5, s3, 0, 5); 
    cout << s4 << endl; 
    
    // Replaces 1 character from 12th  index of s4 with 
    // 3 copies of '!' 
    s4.replace(12, 1, 3, '!'); 
    cout << s4 << endl; 
  
    // Using iterators 
    cout << "\nUsing iterators:"
         << "\n"; 
    // Replaces whole s2 string with s3 
    s2.replace(s2.begin(), s2.end(), s3); 
    cout << s2 << "\n"; 
  
    // Replaces 13 characters from begin of s1 with string 
    // "Example" 
    s1.replace(s1.begin(), s1.begin() + 13, "Example"); 
    cout << s1 << "\n"; 
  
    // Replace last 7 characters of s4 with first 12 
    // characters of the string "geeks from- here" 
    s4.replace(s4.end() - 7, s4.end(), "geeks from- here", 
               12); 
    cout << s4 << "\n"; 
  
    // Replaces last character with complete s2 string from 
    // s2.begin() till s2.end() 
    s4.replace(s4.end() - 1, s4.end(), s2.begin(), 
               s2.end()); 
    cout << s4 << "\n"; 

} 

// vector pairs

void vector_pair(){
        // Declare a vector of pairs of integers
    std::vector<std::pair<int, int>> vecOfPairs;

    // Add some pairs to the vector
    vecOfPairs.push_back(std::make_pair(1, 10));
    vecOfPairs.push_back(std::make_pair(2, 20));
    vecOfPairs.push_back(std::make_pair(3, 30));

    // Accessing elements in the vector of pairs
    std::cout << "Contents of vector of pairs:" << std::endl;
    for (const auto& pair : vecOfPairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }

    // Modifying elements in the vector of pairs
    vecOfPairs[1].second = 25; // Change the second element of the second pair

}