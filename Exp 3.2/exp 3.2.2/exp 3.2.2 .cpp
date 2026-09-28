#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of LCS
int longestCommonSubsequence(string text1, string text2) {

    int m = text1.length();
    int n = text2.length();

    // Create DP table
    // dp[i][j] stores LCS length of first i and first j characters
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            // If characters are same
            if (text1[i - 1] == text2[j - 1]) {

                // Add 1 to the previous diagonal value
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            // If characters are different
            else {

                // Take the maximum of top and left values
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return final LCS length
    return dp[m][n];
}

int main() {

    string text1, text2;

    // Take first string from user
    cout << "Enter first string: ";
    cin >> text1;

    // Take second string from user
    cout << "Enter second string: ";
    cin >> text2;

    // Display LCS length
    cout << "Length of LCS = "
         << longestCommonSubsequence(text1, text2);

    return 0;
}
