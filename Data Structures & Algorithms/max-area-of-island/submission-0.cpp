
class Solution {

    int DFS(vector<vector<int>>& grid, int row, int col, int m, int n) {

        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;

        int area = 1;

        area += DFS(grid, row + 1, col, m, n);
        area += DFS(grid, row - 1, col, m, n);
        area += DFS(grid, row, col + 1, m, n);
        area += DFS(grid, row, col - 1, m, n);

        return area;
    }

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    int area = DFS(grid, i, j, m, n);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
