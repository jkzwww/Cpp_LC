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

void extra_it_ops()
{

    vector<int> vMarks = {20, 80, 70, 65, 43};

    // algo
    //std::random_shuffle(vMarks.begin(), vMarks.end());
    std::sort(vMarks.begin(), vMarks.end());

    //Function for_each(InputIterator first, InputIterator last, Function f);
    std::for_each(vMarks.begin(),vMarks.end(),[](int &mark){ mark += 10;});
    auto print_elem = [](int elem){ cout << elem << "\t";};
    std::for_each(vMarks.begin(),vMarks.end(),print_elem);

}

int main(){

    extra_it_ops();

    return 0;
}