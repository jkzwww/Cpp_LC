// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <thread>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);

    int lb = 4;
    int ub = 6;
    int delay,idx;
    std::string word,typed_word;

    do{
        idx = (rand()*rand())% words->size();
        word = words[idx];

        delay = (rand() % (ub - lb + 1)) + lb;
        std::this_thread::sleep_for (std::chrono::seconds(delay));

        std::cout << "Type: " << word << "\n";
        auto start = std::chrono::steady_clock::now();
        std::getline(std::cin, typed_word);
        auto end = std::chrono::steady_clock::now();

        std::transform(typed_word.begin(), typed_word.end(), typed_word.begin(), toupper);
        double Tpassed = (end-start).count()/1e9;
        
        if(Tpassed > 2){
            std::cout << "------------F A I L------------\n";
            std::cout << "Too slow! Took you " << Tpassed << " s \n" << std::flush;
        }else if(typed_word==word){
            std::cout << "------------S U C C E S S------------\n";
            std::cout << "Congrats! Took you only " << Tpassed << " s \n" << std::flush;
        }else{
            std::cout << "------------F A I L------------\n";
            std::cout << "Wrong spelling! Took you " << Tpassed << " s \n" << std::flush;
        }
        
        // std::cout << "Delayed " << delay << "\n";
        // std::cout << "Chosen " << idx << "\n";
        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');

    return 0;
}
