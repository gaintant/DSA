class Solution {
public:
    void dfs(int i, int p, vector<vector<int>>& adj, int& odd, int &even){
        even++;
        for(auto j : adj[i])
            if(j != p) dfs(j, i, adj, even, odd);
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
    void findAns(vector<vector<int>>& adj, int e, int o, vector<int>& ans, int i =0, int p = -1){
        ans[i] = e;
        for(auto j : adj[i])
            if(j != p)findAns(adj, o, e, ans, j, i);

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int odd1=0, even1 = 0;
        int odd2=0, even2 = 0;
        auto adj1 = findAdj(edges1), adj2 = findAdj(edges2);
        dfs(0, -1, adj1, odd1, even1);
        dfs(0, -1, adj2, odd2, even2);
        int bais = max(odd2, even2);
        // cout<<even1<<" "<<odd1<<" "<<bais<<endl;
        vector<int> ans(adj1.size(), 0);
        findAns(adj1, even1 + bais, odd1 + bais, ans);
        return ans;
    }
};