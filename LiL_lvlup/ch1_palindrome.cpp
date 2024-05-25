// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>
#include <string>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){

    // to lower case
    // std::for_each(str.begin(),str.end(),[](char &c){ c = std::tolower(c);});
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    // reverse
    std::string rev_str = str;
    std::reverse(rev_str.begin(),rev_str.end());

    //check
    return (str==rev_str);

}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}