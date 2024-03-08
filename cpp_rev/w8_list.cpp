/*
List 
- doubly linked list (pointer to next and prev)
- efficient insertion & deletion, O(1)
- slower random access(require traversing through)
- fast access to begin/end of list
- non-contiguous memory allocation (instead of block)

*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    // vector (quick random access, slow insertion or deletion)
    vector<int> vect{40,50,60};
    
    // init
    list<int> li; // empty
    list<int> rp_li(4,1); // size = 4, all elem = 1
    list<int> arr_li{10,20,30}; // direct array
    list<int> vec_li(vect.begin(),vect.end()); // from vector
    list<int> my_list(10); // by lambda function
    int value = 1;
    generate(my_list.begin(),my_list.end(),[&](){return value++;});

    // print
    auto print_elem = [](int elem){ cout << elem << "\t";};
    std::for_each(my_list.begin(),my_list.end(),print_elem);

    // access
    cout << "\nfront elem: " << my_list.front() << endl;
    cout << "back elem: " << my_list.back() << endl;

    // pop
    cout << "\npopped front & back: ";
    my_list.pop_front();
    my_list.pop_back();
    std::for_each(my_list.begin(),my_list.end(),print_elem);

    // push
    cout << "\npushed front & back: ";
    my_list.push_front(100);
    my_list.push_back(500);
    std::for_each(my_list.begin(),my_list.end(),print_elem);

    // sort & reverse
    my_list.sort();
    my_list.reverse();
    cout << "\nsorted & reversed: ";
    std::for_each(my_list.begin(),my_list.end(),print_elem);

    // size
    cout << "\nlist size: " << my_list.size() << endl;

    // insert & erase
    list<int>::iterator iter = my_list.begin();
    advance(iter, 2); // iterator to point to 3rd position
    my_list.insert(iter,200);
    cout << "\niter at : " << *iter;
    cout << "\ninserted 200 : ";
    std::for_each(my_list.begin(),my_list.end(),print_elem);

    advance(iter,2);
    cout << "\niter at : " << *iter;
    my_list.erase(iter);
    cout << "\nerased : ";
    std::for_each(my_list.begin(),my_list.end(),print_elem);

    // deleting range of elements 
    // demoList.erase(itr1, itr2); 

    return 0;
}
