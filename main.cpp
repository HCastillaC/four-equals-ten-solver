#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

struct operations
{
    int sign; //0: +, 1: -, 2: *, 3: /
    int priority;
};

void operate(vector<double long> number, vector<operations> operation, int& number_equalities)
{
    for(int i = 0; i < 3; i++)
    {
        if(operation[i].sign > 1) operation[i].priority = 1;
        else operation[i].priority = 0;
    }

    vector<operations> operation_aux = operation;
    vector<double long> number_aux = number;

    for(int parenthesis_index = 0; parenthesis_index < 6; parenthesis_index++)
    {
        switch(parenthesis_index)
        {
            case 0: operation[0].priority += 2; 
            case 1: operation[1].priority += 2; 
            case 2: operation[2].priority += 2; break;
            case 3: operation[0].priority += 2; 
            case 4: operation[1].priority += 2; break;
            case 5: operation[0].priority += 2; break;
        }

        vector<operations> operation_aux2 = operation;

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
            bool already_done_flag = false;
            number_equalities++;
            if(operation_aux2[0].priority > 1 and parenthesis_index != 0)
            {
                cout << "(";
                already_done_flag = true;
            }
            cout << number_aux[0];
            for(int index = 0; index < 3; index++)
            {
                switch(operation_aux2[index].sign)
                {
                    case 0: cout << " +"; break;
                    case 1: cout << " -"; break;
                    case 2: cout << " *"; break;
                    case 3: cout << " /"; break;
                }
                if(operation_aux2[index + 1].priority > 1 and !already_done_flag and parenthesis_index != 0)
                {
                    cout << " (" << number_aux[index + 1];
                    already_done_flag = true;
                }
                else cout << " " << number_aux[index + 1];
                if(operation_aux2[index + 1].priority < 2 and already_done_flag and parenthesis_index != 0)
                {
                    cout << ")";
                    already_done_flag = false;
                }
            }
            cout << " = 10" << endl;
        }
        operation = operation_aux;
        number = number_aux;
    }
}

void calculate_operations(vector<double long> number, vector<operations> operation, int iteration, int& number_equalities)
{
    if(iteration == 3)
    {
        operate(number, operation, number_equalities);
    } 
    else
    {
        for(int i = 0; i < 4; i++)
        {
            operation[iteration].sign = i;
            calculate_operations(number, operation, iteration + 1, number_equalities);
        }
    }
}

void number_combinations(string remaining_numbers, string set_numbers, int& number_equalities)
{
    if(remaining_numbers == "")
    {
        vector<double long> set_numbers_int;
        vector<operations> operation(3, {0, 0});

        for(int i = 0; i < 4; i++) set_numbers_int.push_back(set_numbers[i] - '0');
        calculate_operations(set_numbers_int, operation, 0, number_equalities);
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

            number_combinations(temp_remaining_numbers, temp_set_numbers, number_equalities);
        }
    }
}

void input(string numbers)
{
    int number_equalities = 0;
    bool is_succesful = false;
    string aux_numbers;

    if(numbers.size() == 4)
    {
        cout << numbers << endl;

        number_combinations(numbers, "", number_equalities);
    
        cout << endl;
        if(number_equalities == 1) cout << "There is 1 solution" << endl;
        else cout << "There are " << number_equalities << " solutions" << endl;
        cout << endl;
        if(number_equalities != 0) is_succesful = true; 
        cout << "is_succesful = " << is_succesful << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            aux_numbers = numbers;
            aux_numbers += i + '0';
            input(aux_numbers);
        }
    }    
}

int main()
{
    char continues = 'y';

    cout << "--------------------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(250));
    cout << " Hugo C presents...                   " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "                      4 = 10          " << endl;
    this_thread::sleep_for(chrono::milliseconds(250));
    cout << "                               Solver " << endl;
    this_thread::sleep_for(chrono::milliseconds(250));
    cout << "--------------------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl;

    while(true)
    {
        cout << "Do you want to solve another puzzle (y / n): ";
        cin >> continues;
        if(continues == 'y') input("");
        else
        {
            cout << "Thanks for using the 4 = 10 Solver!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            break;
        }
    }

    return 0;
}