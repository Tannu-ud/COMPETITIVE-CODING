#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(vector<int>& h, int i, int k) {
    if (i == 0)
        return 0;

    int best = 1000000000;

    for (int j = max(0, i - k); j < i; j++) {
        int cost = solve(h, j, k) + abs(h[i] - h[j]);
        best = min(best, cost);
    }

    return best;
}

int main() {
    int n, k;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> h(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
        cin >> h[i];

    cout << "Enter maximum jump distance k: ";
    cin >> k;

    cout << "Minimum cost = " << solve(h, n - 1, k);

    return 0;
}
