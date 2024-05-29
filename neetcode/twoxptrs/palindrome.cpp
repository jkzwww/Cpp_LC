
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool isPalindrome(std::string s) {

    s.erase(std::remove_if(s.begin(), s.end(),[]( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());

    std::transform(s.begin(), s.end(), s.begin(), tolower);

    std::string rev_str = s;
    std::reverse(rev_str.begin(),rev_str.end());

    return (s==rev_str);
}

bool isPalindrome(std::string s) {

    s.erase(std::remove_if(s.begin(), s.end(),[]( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());

    int left = 0;
    int right = s.length()-1;

    while(left<right){
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(){

    std::string s = "A man, a plan, a canal: Panama";
    std::cout << s << " is a palindrome? " << isPalindrome(s) << std::endl;

    return 0;
}