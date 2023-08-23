#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct operations
{
    int sign; //0: +, 1: -, 2: *, 3: /
    int priority;
};

void operate(vector<double long> number, vector<operations> operation)
{
    for(int i = 0; i < 3; i++)
    {
        if(operation[i].sign > 1) operation[i].priority = 1;
        else operation[i].priority = 0;
    }

    vector<operations> operation_aux = operation;
    vector<double long> number_aux = number;

    for(int priority_index = 3; priority_index > -1; priority_index--)
    {
        for(int operation_index = 0; operation_index < operation.size(); operation_index++)
        {
            if(operation[operation_index].priority == priority_index)
            {
                switch(operation[operation_index].sign)
                {
                    case 0: 
                        number[operation_index] += number[operation_index + 1]; 
                        break;
                    case 1: 
                        number[operation_index] -= number[operation_index + 1]; 
                        break;
                    case 2: 
                        number[operation_index] *= number[operation_index + 1]; 
                        break;
                    case 3: 
                        if(number[operation_index + 1] == 0) break;
                        else
                        {
                            number[operation_index] /= number[operation_index + 1]; 
                            break;
                        }
                }
                if(operation[operation_index].sign == 3 and number[operation_index + 1] == 0) break;
                number.erase(number.begin() + operation_index + 1);
                operation.erase(operation.begin() + operation_index);
                operation_index--;
            }
        }
    }

    if(number[0] == 10 and number.size() == 1)
    {
        cout << number_aux[0];
        for(int index = 0; index < 3; index++)
        {
            switch(operation_aux[index].sign)
            {
                case 0: cout << " +"; break;
                case 1: cout << " -"; break;
                case 2: cout << " *"; break;
                case 3: cout << " /"; break;
            }
            cout << " " << number_aux[index + 1];
        }
        cout << " = 10" << endl;
    }
}

void calculate_operations(vector<double long> number, vector<operations> operation, int iteration)
{
    if(iteration == 3)
    {
        operate(number, operation);
    } 
    else
    {
        for(int i = 0; i < 4; i++)
        {
            operation[iteration].sign = i;
            calculate_operations(number, operation, iteration + 1);
        }
    }
}

void number_combinations(string remaining_numbers, string set_numbers)
{
    if(remaining_numbers == "")
    {
        vector<double long> set_numbers_int;
        vector<operations> operation(3, {0, 0});

        for(int i = 0; i < 4; i++) set_numbers_int.push_back(set_numbers[i] - '0');
        calculate_operations(set_numbers_int, operation, 0);
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