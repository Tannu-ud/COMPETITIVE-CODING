#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    int hash[1000] = {0};
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hash[arr[i]]++;
    }
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] > 1) {
            cout << "Duplicate element: " << arr[i];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Duplicate not found";
    }
    return 0;
}
