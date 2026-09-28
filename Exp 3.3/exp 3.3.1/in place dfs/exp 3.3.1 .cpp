#include <iostream>
#include <vector>
using namespace std;

// DFS function to sink the complete island
void dfs(vector<vector<char>>& grid, int r, int c) {

    int rows = grid.size();
    int cols = grid[0].size();

    // Check if position is outside the grid
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    // Stop if the cell is water
    if (grid[r][c] != '1')
        return;

    // Mark land as water
    // This means the cell is now visited
    grid[r][c] = '0';

    // Visit up
    dfs(grid, r - 1, c);

    // Visit down
    dfs(grid, r + 1, c);

    // Visit left
    dfs(grid, r, c - 1);

    // Visit right
    dfs(grid, r, c + 1);
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

    int count = 0;

    // Check every cell
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            // If land is found
            if (grid[i][j] == '1') {

                // Found a new island
                count++;

                // Sink the complete island
                dfs(grid, i, j);
            }
        }
    }

    cout << "Number of islands = " << count;

    return 0;
}
