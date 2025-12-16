class Solution {
    public void dfs(char[][] grid, boolean[][] vis, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == '0') {
            return;
        }
        vis[i][j] = true;
        dfs(grid, vis, i + 1, j, m, n);
        dfs(grid, vis, i - 1, j, m, n);
        dfs(grid, vis, i, j + 1, m, n);
        dfs(grid, vis, i, j - 1, m, n);
    }
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(grid, vis, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
}