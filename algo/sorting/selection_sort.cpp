
#include <iostream>

void selectionSort(int arr[], int size, int direction){

    for(int i=0; i<size-1; ++i){
        int k;

        if(!direction){
            int min = i;
            // get min elem from unsorted part(>i)
            for(int j=i+1; j<size; ++j){
                if(arr[j]<arr[min]){
                    min = j;
                }
            }
            k = min;
        } else { 
            int max = i;
            //get max elem
            for(int j=i+1; j<size; ++j){
                if(arr[j]>arr[max]){
                    max = j;
                }
            }
            k = max;
        }
        

        // swap the min or max elem to front(i)
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main(){

    int numbers[] = {12,11,13,5,6};
    int n = sizeof(numbers)/sizeof(numbers[0]);

    std::cout << "\nBefore sorting: ";
    for(int i:numbers){
        std::cout << i << "\t";
    }

    selectionSort(numbers,n,0);
    std::cout << "\nAfter sorting (ascending): ";
    for(int i:numbers){
        std::cout << i << "\t";
    }

    selectionSort(numbers,n,1);
    std::cout << "\nAfter sorting (descending): ";
    for(int i:numbers){
        std::cout << i << "\t";
    }


    return 0;
}