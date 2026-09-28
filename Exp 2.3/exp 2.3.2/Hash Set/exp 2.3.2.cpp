#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find duplicate using Hash Set
int findDuplicate(vector<int>& nums)
{
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); i++)
    {
        if (seen.find(nums[i]) != seen.end())
        {
            return nums[i];
        }

        seen.insert(nums[i]);
    }

    return -1;
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
