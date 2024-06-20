#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 10; //compile time constant
const int N = 5;
const int M = 2;

//array
int arr0 [MAX_SIZE]; //declare with [size]
int arr1[] = {80,50,55}; //direct element (size inferred as 3)
char c_arr0[] = "pass"; // = {'p','a','s','s','\0'} (null-terminated character sequence)
char c_arr1[255];
int arr2d[N][M]; //row,columm


//loop 2d array
int main()
{     
    int marks;
    int result[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << "Enter marks of assignment " << j << " for student " << i << " : ";
            cin >> marks;
            result[i][j] = marks;
        }
    }

    return 0;
}

