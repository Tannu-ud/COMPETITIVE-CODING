#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int found = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j] && (j - i) <= k)
            {
                found = 1;
                break;
            }
        }

        if(found == 1)
            break;
    }
    if(found == 1)
        cout << "True";
    else
        cout << "False";
    return 0;
}
