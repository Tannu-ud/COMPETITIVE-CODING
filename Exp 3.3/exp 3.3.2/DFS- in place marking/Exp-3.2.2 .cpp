#include <iostream>
#include <vector>
using namespace std;
// DFS function
void dfs(vector<vector<char>>& grid,
         vector<vector<bool>>& visited,
         int r, int c, int m, int n) {
    // Check boundaries
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;
    // Check water or already visited
    if (grid[r][c] == '0' || visited[r][c])
        return;
    // Mark current cell as visited
    visited[r][c] = true;
    // Visit all four directions
    dfs(grid, visited, r - 1, c, m, n); // Up
    dfs(grid, visited, r + 1, c, m, n); // Down
    dfs(grid, visited, r, c - 1, m, n); // Left
    dfs(grid, visited, r, c + 1, m, n); // Right
}3
// Count number of islands
int numIslands(vector<vector<char>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == '1' && !visited[i][j]) {

                dfs(grid, visited, i, j, m, n);

                count++;
            }
        }
    }

    return count;
}

// Main function
int main() {

    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    cout << "Enter grid elements (0 or 1):\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = numIslands(grid);

    cout << "Number of Islands: " << result << endl;

    return 0;
}
