#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int n, k;

    // Take number of stones
    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> h(n);

    // Take height of each stone
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // Take maximum jump distance
    cout << "Enter maximum jump distance k: ";
    cin >> k;

    // dp[i] stores minimum cost to reach stone i
    vector<int> dp(n, 0);

    // Start from stone 1 and calculate cost for every stone
    for (int i = 1; i < n; i++) {

        // Initially set cost to a very large value
        dp[i] = 1000000000;

        // Check the previous k stones
        for (int j = max(0, i - k); j < i; j++) {

            // Calculate cost of jumping from j to i
            int cost = dp[j] + abs(h[i] - h[j]);

            // Store the minimum cost
            dp[i] = min(dp[i], cost);
        }
    }

    // dp[n-1] contains the minimum cost to reach last stone
    cout << "Minimum cost = " << dp[n - 1];

    return 0;
}
