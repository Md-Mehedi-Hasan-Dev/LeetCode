class Solution {
public:
    vector<int> adj_list[2005];
    bool vis[2005];
    bool pathvis[2005];
    bool cycle;

    void dfs(int src)
    {
        vis[src] = true;
        pathvis[src] = true;
        for(int child : adj_list[src])
        {
            if(vis[child] && pathvis[child])
                cycle = true;
            if(!vis[child])
            {
                dfs(child);
            }
        }
        pathvis[src] = false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        memset(vis, false, sizeof(vis));
        memset(pathvis, false, sizeof(pathvis));
        for(int i = 0; i < e; i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj_list[a].push_back(b);
        }
        cycle = false;
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
                dfs(i);
        }
        return !cycle;
    }
};