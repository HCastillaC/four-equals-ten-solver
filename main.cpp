#include <iostream>
#include <string>

using namespace std;

void checking_operations(string str_numbers)
{
    //Convert to array of ints
    int numbers_int[4];
    int i = 0;

    for(char number_char: str_numbers)
    {
        int number_int = number_char - '0';
        numbers_int[i] = number_int;
        i++;
    }

    //

}

void backtracking(string remaining_numbers, string set_numbers)
{
    if(remaining_numbers == "") cout << set_numbers << endl;
    else
    {
        for(int i = 0; i < remaining_numbers.size(); i++)
        {
            string temp_remaining_numbers = remaining_numbers;
            string temp_set_numbers = set_numbers;
            char selected = remaining_numbers[i];

            temp_remaining_numbers.erase(temp_remaining_numbers.begin() + i);
            temp_set_numbers += selected;

            backtracking(temp_remaining_numbers, temp_set_numbers);
        }
    }
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
    
    backtracking(numbers, "");

    return 0;
}