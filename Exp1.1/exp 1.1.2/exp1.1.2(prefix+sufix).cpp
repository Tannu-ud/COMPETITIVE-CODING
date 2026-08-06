#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size: ";
    cin >> n;
    int arr[n], pre[n], suf[n], ans[n];
    cout<<"Enter array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    pre[0] = 1;
    for(int i = 1; i < n; i++)
        pre[i] = pre[i - 1] * arr[i - 1];
    suf[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] * arr[i + 1];
    for(int i = 0; i < n; i++)
        ans[i] = pre[i] * suf[i];
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
