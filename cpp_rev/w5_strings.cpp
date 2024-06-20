#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

void c_strings(){
    // char array
    // c-style string, pointer to first char 
    // passing array in func is similar to passing pointer to 1st elem
    char c_arr[] = "Alex"; 
    const char* cstr = "Alex";

    cout << cstr[2] << '\n'; // access

    std::string str = cstr;     // Cstring -> string

    const char* cstr2 = str.c_str(); // string -> Cstring
}
 
void cstring_manipulation(){
    // string comparison function
    // comparison is based on the ASCII values of characters (lexicographically)
    char s1[50] = "aomomo";
    char s2[10] = "mikan";
    int result = strcmp(s1, s2); // 0:equal,neg:s1<s2,pos:s1>s2
    cout << "compared : " << result << '\n';

    // string concatenation
    strcat_s(s1, s2); // s1 has to be large enough for s2
    cout << "concatenated: " << s1 << '\n';

    // string copy(replace)
    strcpy_s(s1, s2);
    cout << "copied: " << s1 << '\n';

    // string length
    size_t strsize = strlen(s1); // size_t:int that cant be negative

    cout << "size: " << strsize << '\n';
    
    // create substring
    string myStr = "karappo";
    string substr;

    // finding char
    int rPos = myStr.find("r");
    if (rPos != string::npos){
         substr = myStr.substr(0, rPos); 
    }
    cout << "substring: " << substr << '\n';

    // transformation
    transform(myStr.begin(), myStr.end(), myStr.begin(), 
                [](char c){return toupper(c);});
    cout << "transformed: " << myStr;
}

//c++ string, dynamic
void strings(){
    
    string s1 = "hello";
    string s2 = "world";

    //concat
    string s3 = s1 + " " + s2 + "!"; 
    cout << "concat string: " << s3 << '\n';

    // length
    cout << "string length: " << s3.length() << '\n';

    // access
    cout << "1st char: " << s3[0] << '\n';
    cout << "last char: " << s3.back() << '\n';

    // substring
    string substr = s3.substr(6,6);
    cout << "substring: " << substr << '\n';

    /* iterators: begin() , end()
    capacity: size() , length() , clear() , empty()
    modifier: append(), insert() , erase() , replace()
    operator: find() , substr() */
}



int main(){

    // cstring_manipulation();
    strings();

    return 0;
}