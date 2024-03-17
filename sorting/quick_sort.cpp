#include <iostream>

// function to partition index based on a pivot point
// smaller goes left, larger goes right of pivot
int partition(int arr[],int start,int end){

    int pivot = arr[end]; // last elem as pivot
    int idx = start; // keep track of smaller elems

    for(int i=start; i<end; i++){
        
        // swap i with idx elem if < pivot
        if(arr[i] < pivot){
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
            idx++;
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

    // havent finish sorting yet
    if(start < end){
        int d = partition(arr,start,end);
        quickSort(arr,start,d-1);
        quickSort(arr,d+1,end);
    }
}

int main(){

    int numbers[] = {12,11,13,5,6};
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