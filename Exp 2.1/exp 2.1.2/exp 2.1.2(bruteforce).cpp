#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void solve(vector<int> &a, int target, vector<int> &temp)
{
    if (target == 0)
    {
        sort(temp.begin(), temp.end());

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == temp)
                return;
        }

        ans.push_back(temp);
        return;
    }

    if (target < 0)
        return;

    for (int i = 0; i < a.size(); i++)
    {
        temp.push_back(a[i]);

        solve(a, target - a[i], temp);

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

    solve(a, target, temp);

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
