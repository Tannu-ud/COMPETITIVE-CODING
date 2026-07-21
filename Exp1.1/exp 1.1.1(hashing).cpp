#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of arrray: ";
    cin >> n;
    int arr[n];
    int hash[1000] = {0};
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] > 1) {
            cout << "Duplicate element: " << arr[i];
            break;
        }
    }
    return 0;
}
