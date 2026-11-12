#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid,
         vector<vector<bool>>& visited,
         int r, int c, int m, int n) {

    if (r < 0 || c < 0 || r >= m || c >= n)
        return;

    if (grid[r][c] == '0' || visited[r][c])
        return;

    visited[r][c] = true;

    dfs(grid, visited, r - 1, c, m, n);
    dfs(grid, visited, r + 1, c, m, n);
    dfs(grid, visited, r, c - 1, m, n);
    dfs(grid, visited, r, c + 1, m, n);
}

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
    cout << "Number of Islands: " << numIslands(grid);
    return 0;
}
