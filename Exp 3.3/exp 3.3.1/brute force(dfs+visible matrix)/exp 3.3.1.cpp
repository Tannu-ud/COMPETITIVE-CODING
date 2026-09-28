#include <iostream>
#include <vector>
using namespace std;

// DFS function to visit all connected land cells
void dfs(vector<vector<char>>& grid,
         vector<vector<bool>>& visited,
         int r, int c) {

    int rows = grid.size();
    int cols = grid[0].size();

    // Check if position is outside the grid
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    // Stop if it is water or already visited
    if (grid[r][c] == '0' || visited[r][c])
        return;

    // Mark current cell as visited
    visited[r][c] = true;

    // Visit up
    dfs(grid, visited, r - 1, c);

    // Visit down
    dfs(grid, visited, r + 1, c);

    // Visit left
    dfs(grid, visited, r, c - 1);

    // Visit right
    dfs(grid, visited, r, c + 1);
}

int main() {

    int rows, cols;

    // Take number of rows and columns
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    // Take grid input
    cout << "Enter grid (0 for water, 1 for land):\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // Create visited matrix
    vector<vector<bool>> visited(
        rows, vector<bool>(cols, false)
    );

    int count = 0;

    // Check every cell
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            // If unvisited land is found
            if (grid[i][j] == '1' && !visited[i][j]) {

                // One new island found
                count++;

                // Visit the complete island
                dfs(grid, visited, i, j);
            }
        }
    }

    cout << "Number of islands = " << count;

    return 0;
}
