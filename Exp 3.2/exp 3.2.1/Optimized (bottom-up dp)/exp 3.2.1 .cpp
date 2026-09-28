#include <iostream>
#include <vector>
using namespace std;

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

    // dp[i] = minimum coins needed to make amount i
    // amount + 1 means the amount is currently unreachable
    vector<int> dp(amount + 1, amount + 1);

    // 0 coins are needed to make amount 0
    dp[0] = 0;

    // Calculate answer for every amount from 1 to target
    for (int i = 1; i <= amount; i++) {

        // Try every coin
        for (int coin : coins) {

            // Use the coin if it is not greater than current amount
            if (coin <= i) {

                // Take the minimum number of coins
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If target is still unreachable, return -1
    if (dp[amount] > amount)
        cout << "Minimum coins = -1";
    else
        cout << "Minimum coins = " << dp[amount];

    return 0;
}
