#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find minimum coins for the given amount
int solve(vector<int>& coins, int amount) {

    // Base case: amount 0 needs 0 coins
    if (amount == 0)
        return 0;

    // Start with a very large value
    int best = INT_MAX;

    // Try every coin
    for (int coin : coins) {

        // Use the coin only if it is not greater than amount
        if (coin <= amount) {

            // Find coins needed for remaining amount
            int result = solve(coins, amount - coin);

            // If remaining amount is possible
            if (result != INT_MAX)
                best = min(best, result + 1);
        }
    }

    return best;
}

int main() {

    int n, amount;

    // Input number of coins
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    // Input coin denominations
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // Input target amount
    cout << "Enter amount: ";
    cin >> amount;

    int answer = solve(coins, amount);

    // If amount cannot be formed
    if (answer == INT_MAX)
        cout << "Minimum coins = -1";
    else
        cout << "Minimum coins = " << answer;

    return 0;
}
