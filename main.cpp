#include <iostream>
#include <string>

using namespace std;

string backtracking(string reamining_numbers, string set_numbers)
{
    //if(set_numbers)
}

int main()
{
    string numbers = "";
    char input;

    while(numbers.size() < 4)
    {
        cout << "Input number " << numbers.size() + 1 << ": ";
        cin >> input;

        if(input == '0' or input == '1' or input == '2' or input == '3' or input == '4' or input == '5' or
        input == '6' or input == '7' or input == '8' or input == '9') numbers += input;
    }

    cout << endl << numbers;
    
    //backtracking(numbers, )

    return 0;
}