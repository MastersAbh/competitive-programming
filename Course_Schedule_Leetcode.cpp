class Solution {
public:
    bool dfs(int node, vector <int>& vis, vector <int>& st, vector <int> graph[]) {
        if(!vis[node]) {
            vis[node] = 1;
            st[node] = 1;
            for(int i = 0; i < graph[node].size(); i++) {
                if(!vis[graph[node][i]] && dfs(graph[node][i], vis, st, graph)) {
                    return true;
                }
                else if(st[graph[node][i]])
                    return true;
            }
        }
        st[node] = 0;
        return false;
    }
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector <int> vis(num+1, 0);
        vector <int> st(num+1, 0);
        vector <int> graph[num+1];
        for (int i = 0; i < pre.size(); i++) {
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i = 0; i < pre.size(); i++) {
            if(!vis[pre[i][1]])
                if(dfs(pre[i][1], vis, st, graph)) return false;
        }
        return true;
    }
};
