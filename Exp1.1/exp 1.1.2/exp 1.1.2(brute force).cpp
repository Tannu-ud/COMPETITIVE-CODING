#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size: ";
    cin >> n;
    int nums[n], ans[n];
    cout<<"Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++) {
        ans[i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j)
                ans[i] *= nums[j];
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
