#include <iostream>
using namespace std;

int main()
{
    int n, target;
    cout<<"Enter size: ";
    cin >> n;
    int arr[n];
    cout<<"Enter array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<"Enter target: ";
    cin >> target;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
