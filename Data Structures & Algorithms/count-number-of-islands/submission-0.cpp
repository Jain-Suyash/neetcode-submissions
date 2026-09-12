class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        function<void(int, int)> dfs = [&](int r, int c) {
            grid[r][c] = '0';

            if (r > 0 && grid[r - 1][c] == '1') dfs(r - 1, c);
            if (r + 1 < rows && grid[r + 1][c] == '1') dfs(r + 1, c);
            if (c > 0 && grid[r][c - 1] == '1') dfs(r, c - 1);
            if (c + 1 < cols && grid[r][c + 1] == '1') dfs(r, c + 1);
            return;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j);
                }
            }
        }

        return count;
    }
};
