#include <iostream>
#include <vector>

using namespace std;

// function to partition index based on a pivot point
// smaller goes left, larger goes right of pivot
// put all smaller number starting from idx(start) then put pivot after, leaving all larger untouched at back
int partition(int arr[],int start,int end){

    int pivot = arr[end]; // last elem as pivot 
    int idx = start; // keep track of smaller elems

    for(int i=start; i<end; i++){
        
        // swap i with idx elem if < pivot
        if(arr[i] <= pivot){
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
            idx++;
            // std::cout << "\nswapped " << temp << "\n";
        }

    }
    // put back pivot at idx (division point)
    arr[end] = arr[idx];
    arr[idx] = pivot;

    return idx; // division index
}

// quick sort. recursive function
// takes in starting and ending index of the parts
void quickSort(int arr[], int start, int end){

    if(start >= end) return;

    int d = partition(arr,start,end); // partition array
    quickSort(arr,start,d-1); // sort left part
    quickSort(arr,d+1,end); // sort right part

}

int main(){

    int numbers[] = {12,11,11,13,5,7,6,7};
    int n = sizeof(numbers)/sizeof(numbers[0]);

    std::cout << "\nBefore sorting: ";
    for(int i:numbers){
        std::cout << i << "\t";
    }

    quickSort(numbers,0,n-1);
    std::cout << "\nAfter sorting (ascending): ";
    for(int i:numbers){
        std::cout << i << "\t";
    }

    return 0;
}