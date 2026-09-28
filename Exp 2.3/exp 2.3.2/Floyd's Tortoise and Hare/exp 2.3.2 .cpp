#include <iostream>
#include <vector>
using namespace std;

// Function to find duplicate using Floyd's Cycle Detection
int findDuplicate(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Find the meeting point
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

    } while (slow != fast);

    // Phase 2: Find the entrance of the cycle
    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(n + 1);

    cout << "Enter " << n + 1 << " elements: ";

    for (int i = 0; i < n + 1; i++)
    {
        cin >> nums[i];
    }

    int result = findDuplicate(nums);

    cout << "Duplicate number: " << result << endl;

    return 0;
}
