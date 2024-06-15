
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>

// single func implementation
void bubble_sort(int* arr,int size){

    bool sorted = false;
    int temp;

    while(!sorted){
        sorted = true;

        for(int i={}; i<size-1; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = false;
            }
        }
    }
}

void bubbleSort(int row[],int size,int direction);
bool ascending(int left, int right);
bool descending(int left, int right);
void swap(int* left, int* right);
void swapChar(char* left, char* right);
void bubbleSortStr(char word[],int size,int direction);

int main()
{
    srand(time(NULL));

    const int SIZE = 10;

    int input_int[SIZE];
    
    printf("Before sorting: \n");
    for(int i{}; i<SIZE; ++i){
        input_int[i] = rand()%9;
        std::cout << input_int[i] << "\t";
    }
    
    bubbleSort(input_int,SIZE,0);

    printf("\nAfter sorting: (ascending) \n");
    for(int num : input_int){
        std::cout << num << "\t";
    }
  
    bubbleSort(input_int,SIZE,1);\
    
    printf("\nAfter sorting: (descending) \n");
    for(int num : input_int){
        std::cout << num << "\t";
    }
    

    // sort string
    char input_str[] = "skdfjh";
    int n = strlen(input_str);

    printf("\nBefore sorting: %s \n",input_str);

    bubbleSortStr(input_str,n,0);
    printf("\nAfter sorting (ascending): %s \n",input_str);

    bubbleSortStr(input_str,n,1);
    printf("\nAfter sorting (descending): %s \n",input_str);

    return 0;
}

// sort integer array, direction ? ascending:descending
void bubbleSort(int row[],int size, int direction)
{
    //array of pointer to function
    bool(*asc_dec[2])(int left,int right) = {ascending,descending};

    //bubble sort , loop size-1 time
    //loop each element through
    for (int sortIndex = 0; sortIndex < size-1 ; sortIndex++)
    {
        //loop current sort index through current array
        for(int comparePass = 0; comparePass < size-sortIndex-1; comparePass++)
        {
            //decide which comparison func to use
            if(asc_dec[direction](row[comparePass],row[comparePass+1]))
            {
                swap(&row[comparePass],&row[comparePass+1]);
            }
    
        }
    }
}

//true if need to swap
bool ascending(int left, int right)
{
    return left > right;
}

bool descending(int left, int right)
{
    return left < right;
}

void swap(int* left, int* right)
{
    int temp;
    temp = *left;
    *left = *right;
    *right = temp;
}

void swapChar(char* left, char* right)
{
    char temp;
    temp = *left;
    *left = *right;
    *right = temp;
}

// sort string
void bubbleSortStr(char word[],int size,int direction){
    
    for(int i{};i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            
            bool result = word[j]>word[j+1];
            if((!direction && result) || (direction && !result)){
                swapChar(&word[j], &word[j+1]);
            }
        }
    }
}

