#include <iostream>
using namespace std;
int main()
{
    int n, target;
    cout<<"Enter size: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> target;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
        {
            cout << mid;
            return 0;
        }
        if(arr[low] <= arr[mid])
        {
            if(target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if(target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    cout << -1;
    return 0;
}
