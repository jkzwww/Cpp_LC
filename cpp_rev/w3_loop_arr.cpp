#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//format : ctrl+k , ctrl+f;

//if statement
int main()
{
    int birthday = 5;
    cout << "please enter your birthday month: ";
    cin >> birthday;

    if (birthday >= 3 && birthday <= 6)
    {
        cout << "spring!\n\n";
    }
    else if (birthday > 6 && birthday <= 9)
    {
        cout << "summer!\n\n";
    }
    else if (birthday > 9 && birthday <= 11)
    {
        cout << "autumn!\n\n";
    }
    else
    {
        cout << "winter!\n\n";
    }

    return 0;
}


//switch
int main()
{
    int experience;
    cout << "Please rate your experience (0-3): ";
    cin >> experience;

    string review;

    switch (experience)
    {
    case 0:
        cout << "Sorry for bad experience!Please contact customer service if needed." << endl;
        break;

    case 1:
        cout << "Thanks for rating!Please tell us where to improve:";
        cin.ignore(); // clear input buffer before reading
        getline( cin, review );
        break;
    
    case 3:
        cout << "We're happy that you are satisfied!";
        break;

    default:
        cout << "Thank you and please come again!" << endl;
    }

}


//while loop
int main()
{
    int cards;
    cout << "How many cards do you have now?";
    cin >> cards;

    while (cards > 0)
    {
        if (cards == 1)
        {
            cout << "Last card!\n\n";
        }
        else
        {
            cout << "wait for next round!\n\n";
        }
        cout << "How many cards do you have now?";
        cin >> cards;
 
    }
    cout << "\n\tU\tN\tO\t!!!\n";

}


//dowhile loop
int main()
{
    char again = 'x';

    do
    {
        cout << "Do You Want To Play Again? (y/n): ";
        cin >> again;
    } 
    while (again == 'y');

    cout << "OK, catch you later";
}


//for loop and array
int main()
{
    const int NUM_STUDENTS = 10;
    int examMarks[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) //initialisation;check;action
    {
        examMarks[i] = 0;  //initialise all marks
        cout << examMarks[i];
    }

}

//array
int examMarks [50]; //declare with [size]

int examMarks[] = {80,50,55}; //direct element (size inferred as 3)

char mygrade[] = "pass"; // = {'p','a','s','s','\0'} (null-terminated character sequence)

char mygrade[80];
 

//2D arrays
const int NUM_STUDENTS = 5;
const int NUM_MARKS = 4;
int marks[NUM_STUDENTS][NUM_MARKS]; //row,columm


//initialise and calculation with for loops for arrrays
int main()
{
    int marks;
    int result[4][3];
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << "Enter marks of assignment " << col << " for student " << row << " : ";
            cin >> marks;
            result[row][col] = marks;
        }
    }

    for (int col = 0; col < 3; col++)
    {
        float total = 0;

        for (int row = 0; row < 4; row++)
        {
            total += result[row][col];
        }

        cout << "\nAssignment " << col << " average : " << total / 5 << endl;

    }

}


//array loop
int main()
{
  int myarray[3] = {10,20,30};

  for (int i=0; i<3; ++i)
    ++myarray[i];

  for (int elem : myarray)
    cout << elem << '\n';
}
