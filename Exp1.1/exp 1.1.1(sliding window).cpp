#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    int n, k;
    cout<<"Enter size: ";
    cin >> n;
    cout<<"Enter target:";
    cin>>k;
    int arr[n];
    cout<<"Enter array:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.count(arr[i])) {
            cout << "True";
            return 0;
        }
        s.insert(arr[i]);
        if (s.size() > k)
            s.erase(arr[i - k]);
    }
    cout << "False";
    return 0;
}
