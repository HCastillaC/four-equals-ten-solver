#include <iostream>

using namespace std;

int main()
{
    int numbers[4];

    for(int i = 0; i < 4; i++)
    {
        cout << "Input number " << i + 1 << ": " << endl;
        cin >> numbers[i];
        cout << endl;
    }

    return 0;
}