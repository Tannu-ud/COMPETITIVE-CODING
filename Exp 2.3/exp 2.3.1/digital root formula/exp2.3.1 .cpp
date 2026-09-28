#include <iostream>
using namespace std;

// Function to find digital root using formula
int addDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return 1 + (num - 1) % 9;
}

int main()
{
    int num;

    cout << "Enter a non-negative integer: ";
    cin >> num;

    int result = addDigits(num);

    cout << "Single digit result: " << result << endl;

    return 0;
}
