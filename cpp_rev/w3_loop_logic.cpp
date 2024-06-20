#include <iostream>
#include <string>
#include <vector>
using namespace std;

// if statement
void if_statement()
{
    int birthday;
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

}


// switch
void switch_statement()
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


// while loop
void while_loop()
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


// dowhile loop
void dowhile_loop()
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


// for loop
void for_loop()
{
    vector<int> arr1 = {1,2,3};
    const int N = 3;
    int arr2[N] = {4,5,6};

    // auto range
    for(auto& i:arr1){ cout << i; };

    // traditional with idx
    for(int i{}; i<arr1.size(); i++){ cout << arr1[i]; };
    
    for(int j{}; j<N; j++){ cout << arr2[j]; };
}