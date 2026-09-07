#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;

void solve(vector<int> &a, int target, int start, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i < a.size(); i++)
    {
        if (a[i] > target)
            continue;

        temp.push_back(a[i]);

        solve(a, target - a[i], i, temp);

        temp.pop_back();
    }
}

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> temp;

    solve(a, target, 0, temp);

    cout << "\nAll possible combinations are:\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "]\n";
    }

    return 0;
}
