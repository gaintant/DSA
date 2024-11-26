class Solution {
public:
    int findParent(vector<int> &parent, int j){
        if(parent[j] == j)
            return j;
        return parent[j] = findParent(parent, parent[j]);
    }
    void union_find(vector<int> &parent, int i, int j){
        parent[findParent(parent, j)] = findParent(parent, i);

    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> parent(n, false);
        for(auto edge : edges){
            parent[edge[1]] = true;
        }
        int c = 0, ans = -1;
        for(int i=0; i<n; i++)
            if(parent[i] == false){
                c++;
                ans = i;
            };
        return c == 1 ? ans : -1;
    }
};