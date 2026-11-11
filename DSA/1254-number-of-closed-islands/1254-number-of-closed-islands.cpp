class Solution {
public:
    int n, m;
    bool flag;
    bool vis[105][105];
    vector<pair<int, int>> mov = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool valid(int i, int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid)
    {
        vis[si][sj] = true;
        for(int i = 0; i < 4; i++)
        {
            int ci = si + mov[i].first;
            int cj = sj + mov[i].second;
            if(!valid(ci, cj)) flag = false;
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
                dfs(ci, cj, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));
        int cnt = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && grid[i][j] == 0)
                    {
                        flag = true;
                        dfs(i, j, grid);
                        if(flag) cnt++;
                    }
        return cnt;
    }
};