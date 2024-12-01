class Solution {
public:
    int dfs(int i, int p, vector<vector<int>> &adj, int k){
        if(k == -1)
            return 0;
        int ans = 1;
        for(auto j : adj[i]){
            if(j != p) ans += dfs(j,i,adj, k-1);
        }
        return ans;
    } 
    vector<vector<int>> findAdj(vector<vector<int>>& edges){
        int n  =edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k){
        auto adj1 = findAdj(edges1), adj2 = findAdj(edges2);
        int n = adj1.size(), m = adj2.size();
        vector<int> ans(n, 0);
        int bais = 0;
        for(int i=0; i<m; i++){
            bais = max(bais, dfs(i, -1, adj2, k-1));
        }
        for(int i=0; i<n; i++){
            ans[i] = dfs(i, -1, adj1, k) + bais;
        }
        return ans;
    }
};