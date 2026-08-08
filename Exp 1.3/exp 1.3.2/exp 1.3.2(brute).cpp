#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter heights of bars:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }

        s.push(i);
    }
    cout << "Largest rectangle area: " << maxArea << endl;
    return 0;
}
