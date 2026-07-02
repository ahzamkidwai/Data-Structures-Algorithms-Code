class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size();
        int col = grid[0].size();

        // Health after entering the starting cell
        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        queue<pair<pair<int, int>, int>> q;

        // best[i][j] = maximum health remaining when reaching (i, j)
        vector<vector<int>> best(row, vector<int>(col, -1));

        best[0][0] = startHealth;
        q.push({{0, 0}, startHealth});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int h = curr.second;

            if (r == row - 1 && c == col - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
                    int newHealth = h - grid[nr][nc];

                    if (newHealth > 0 && newHealth > best[nr][nc]) {
                        best[nr][nc] = newHealth;
                        q.push({{nr, nc}, newHealth});
                    }
                }
            }
        }

        return false;
    }
};