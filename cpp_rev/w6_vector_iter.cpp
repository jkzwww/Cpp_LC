#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void vector_event()
{

    vector<int> vec; // no size,dynamic
    vec = {50,3,2,7};

    // initialise
    size_t size = 50;
    int init_elem = 0;
    vector<int> vec2(size,init_elem);
    
    // access vector
    cout << "vec elem: " << vec[2];
    vec.front(); // access first element 
    vec.back(); // access last element 
    
    // modify
    vec.push_back(75); // next spot available
    vec.pop_back();    // delete last thing
    
    // memory
    vec.resize(20);   // set the size manually
    vec.reserve(10); // reserve size similar as array
    vec.clear();     // clears vector

    vec.size();     // check size (elements num)
    vec.capacity(); // amount of memory allocated(might > elements)
    vec.empty();    // check whether empty
}

// vector pairs
void vector_pair(){
    // Declare a vector of pairs of integers
    vector<pair<int, int>> vecOfPairs;

    auto pair1 = make_pair(1, 10);
    // Add some pairs to the vector
    vecOfPairs.push_back(pair1);
    vecOfPairs.push_back(make_pair(3, 30));
    vecOfPairs.push_back(make_pair(2, 20));

    // sort pairs based on first val of pair
    sort(vecOfPairs.begin(),vecOfPairs.end());

    // Accessing elements in the vector of pairs
    for (const auto& pair : vecOfPairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }

    // Modifying elements in the vector of pairs
    vecOfPairs[1].second = 25; // Change the second element of the second pair

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
    vector<int> vec = {20, 80, 70, 65, 43};
    
    // classname<param>::iterator name
    vector<int>::iterator iter; // declare iterator for a vector of int
    
    // deref
    for (iter = vec.begin(); iter != vec.end(); iter++){ cout << *iter << " ";}

    // used to insert things and will move everything in place
    vec.insert(vec.begin() + 1, 90);
    vec.erase(vec.begin(), vec.begin() + 2);

    // find item
    vector<int>::iterator finder_iter;
    finder_iter = find(vec.begin(), vec.end(), 70); 
    // found if != vec.end()
    if (finder_iter != vec.end()){
        int finder_idx = std::distance(vec.begin(), finder_iter); // get idx
        cout << "Item found : " << *finder_iter << "\n";
        cout << "Position : " << finder_idx << "\n";
    }

    
    //Function for_each(InputIterator first, InputIterator last, Function f);
    std::for_each(vec.begin(),vec.end(),[](int &i){ i += 10;});

    auto print_elem = [](int elem){ cout << elem << "\t";};
    std::for_each(vec.begin(),vec.end(),print_elem);
    
    vector<int> nums = {1,2,3,4,5};
    int x = 3;
    std::for_each(nums.begin(),nums.end(),[x](int &no){ if(no != x){no *= 10;}});
   
    // sorting
    sort(vec.begin(), vec.end());

    vector<int> sqvec;

    //Function transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);

    // store result at another output vector
    // back_inserter(vect) output iterator which uses push_back (automatic resize)
    std::transform(vec.begin(),vec.end(),std::back_inserter(sqvec),[](int x){return x*x;});

    // inplace modification
     std::transform(vec.begin(), vec.end(), vec.begin(), [](int n) { return 5*n; });

}




 


