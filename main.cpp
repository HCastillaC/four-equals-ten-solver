#include <iostream>
#include <string>

using namespace std;

void operate(int number[], int operation[])
{
    int operation_priority[3];

    for(int i = 0; i < 3; i++)
    {
        if(operation[i] > 1) operation_priority[i] = 1;
        else operation_priority[i] = 0;
    }
}

void calculate_operations(int number[], int operation[], int iteration)
{
    if(iteration == 3)
    {
        operate(number, operation);
    } 
    else
    {
        for(int i = 0; i < 4; i++)
        {
            operation[iteration] = i;
            calculate_operations(number, operation, iteration + 1);
        }
    }
}

void number_combinations(string remaining_numbers, string set_numbers)
{
    if(remaining_numbers == "")
    {
        int set_numbers_int[4];
        int operation[3] = {0, 0, 0};
        for(int i = 0; i < 4; i++) set_numbers_int[i] = set_numbers[i] - '0';
        calculate_operations(set_numbers_int, operation, 0);
        cout << endl;
    }
    else
    {
        for(int i = 0; i < remaining_numbers.size(); i++)
        {
            string temp_remaining_numbers = remaining_numbers;
            string temp_set_numbers = set_numbers;
            char selected = remaining_numbers[i];

            temp_remaining_numbers.erase(temp_remaining_numbers.begin() + i);
            temp_set_numbers += selected;

            number_combinations(temp_remaining_numbers, temp_set_numbers);
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
    
    number_combinations(numbers, "");

    return 0;
}