// C++ Code Challenges, LinkedIn Learning

// Challenge #9: Fixing Faulty Code
// Fix the bugs in the provided code.
// The application is supposed to ask the user for a string, and print the number of vowels contained in the string.

// For example: 
// "I love my dog" has 4 vowels, "education" has 5 vowels, and "Sly spy by my crypt" has 0 vowels.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// vowel_count()
// Summary: This function counts the number of vowels in an incoming string.
// Arguments:
//           str: The string to analyze.
// Returns: An integer with the vowel count.
int vowel_count(std::string str){
    int count=0;
    std::vector<char> vowels = {'a','e','i','o','u'};
   std::transform(str.begin(), str.end(), str.begin(), tolower);

    for(int i{}; i<str.length(); i++)
    {
        std::vector<char>::iterator finder; 
        finder = std::find(vowels.begin(), vowels.end(), str[i]);
        if (finder != vowels.end()) {
            count++;
        }
        
    }

    return count;
}

// Faulty code, main()
// Summary: This application ask the user for a string, and prints the number of vowels in it.
int main(){
    std::string input; 
    std::cout << "Enter some text: " << std::flush;
    std::getline(std::cin,input);
    std::cout << "\nThe text you entered contains " << vowel_count(input) << " vowels.\n\n";

    return 0;
}
 