class Solution {
public:
    int n, m;
    bool vis[505][505];
    vector<pair<int, int>> mov = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isSubIsland;

    bool valid(int i, int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        vis[si][sj] = true;
        if(grid1[si][sj] == 0)
            isSubIsland = false;
        for(int i = 0; i < 4; i++)
        {
            int ci = si + mov[i].first;
            int cj = sj + mov[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
                dfs(ci, cj, grid1, grid2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        n = grid1.size();
        m = grid1[0].size();
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && grid2[i][j] == 1)
                {
                    isSubIsland = true;
                    dfs(i, j, grid1, grid2);
                    if(isSubIsland)
                        cnt++;
                }
        return cnt;
    }
};