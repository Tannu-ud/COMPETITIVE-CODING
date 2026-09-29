// LeetCode Problem 34

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int first = -1, last = -1;

    // Checking the array to find the first and last position
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {

            // Store the first occurrence only once
            if (first == -1)
                first = i;

            // Keep updating last whenever target is found
            last = i;
        }
    }

    return {first, last};
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    // Function returns both starting and ending positions
    vector<int> result = searchRange(nums, target);

    cout << "First and last position: ";
    cout << "[" << result[0] << ", " << result[1] << "]";

    return 0;
}
