#include <iostream>

void insertionSort(int arr[], int size, int direction){
    
    // start comparision from 2nd elem to prior elems
    for(int i=1; i<size; ++i){

        int key = arr[i];
        int j = i - 1;

        // ascending: move arr[j] backwards if > key
        // descending: move arr[j] backwards if < key
        while(j>=0 && ((!direction && arr[j]>key)||(direction && arr[j]<key))){
            arr[j+1] = arr[j];
            --j;
        }
        // put back key to empty space(last moved elem)
        arr[j+1] = key;

    }
    
}

int main(){

    int numbers[] = {12,11,13,5,6};
    int n = sizeof(numbers)/sizeof(numbers[0]);

    std::cout << "\nBefore sorting: ";
    for(int i:numbers){
        std::cout << i << "\t";
    }

    insertionSort(numbers,n,0);
    std::cout << "\nAfter sorting (ascending): ";
    for(int i:numbers){
        std::cout << i << "\t";
    }

    insertionSort(numbers,n,1);
    std::cout << "\nAfter sorting (descending): ";
    for(int i:numbers){
        std::cout << i << "\t";
    }


    return 0;
}