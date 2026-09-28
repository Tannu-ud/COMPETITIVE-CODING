#include <iostream>
using namespace std;

// Function to add digits repeatedly
int addDigits(int num)
{
    while (num >= 10)
    {
        int sum = 0;

        while (num > 0)
        {
            sum = sum + (num % 10);
            num = num / 10;
        }

        num = sum;
    }

    return num;
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
