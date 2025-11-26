class Solution {
public:
    const int mod = 1e9 + 7;
    int dfs(int r, int c, int sum, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(r >= n || c >= m) return 0;
        int rem = (sum + grid[r][c]) % k;
        if(r == n-1 && c == m-1) return (rem == 0) ? 1 : 0;
        if(dp[r][c][rem] != -1) return dp[r][c][rem];

        int left = dfs(r+1, c, sum + grid[r][c], grid, k, dp);
        int right = dfs(r, c+1, sum + grid[r][c], grid, k, dp);
        return dp[r][c][rem] = ((left % mod) + (right % mod)) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(51, -1)));
        return dfs(0, 0, 0, grid, k, dp);
    }
};