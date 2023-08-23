#include <iostream>
#include <string>

using namespace std;

void operate(int number[], int operation_priority[], int set_operation[])
{
    for(int i = 0; i < 4; i++) cout << number[i];
    cout << endl;
    for(int i = 0; i < 3; i++) cout << operation_priority[i];
    cout << endl;
    for(int i = 0; i < 3; i++) cout << set_operation[i];
    cout << endl;
    cout << endl;
}

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

    //Try all the operations

    for(int parenthesis_index = 0; parenthesis_index < 6; parenthesis_index++)
    {
        int operation_priority[3] = {0, 0, 0};
        //* 0: + ; 1: - ; 2: * ; 3: /
        int set_operation[3] = {0, 0, 0};

        switch(parenthesis_index)
        {
            case 0: operation_priority[0] += 2;
            case 1: operation_priority[1] += 2;
            case 2: operation_priority[2] += 2; break;
            case 3: operation_priority[0] += 2;
            case 4: operation_priority[1] += 2; break;
            case 5: operation_priority[0] += 2; break;
        }
        for(int first_operation_index = 0; first_operation_index < 4; first_operation_index++)
        {
            set_operation[0] = first_operation_index;
            if(first_operation_index == 2) operation_priority[0]++;
            for(int second_operation_index = 0; second_operation_index < 4; second_operation_index++)
            {
                set_operation[1] = second_operation_index;
                if(second_operation_index == 2) operation_priority[1]++;
                for(int third_operation_index = 0; third_operation_index < 4; third_operation_index++)
                {
                    set_operation[2] = third_operation_index;
                    if(third_operation_index == 2) operation_priority[2]++;
                    operate(numbers_int, operation_priority, set_operation);
                }
            }
        }
    }

}

void backtracking(string remaining_numbers, string set_numbers)
{
    if(remaining_numbers == "") checking_operations(set_numbers);
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