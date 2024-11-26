class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> parent(n, false);
        int c = 0, ans = -1;
        for(auto edge : edges){
            parent[edge[1]] = true;
        }
        for(int i=0; i<n; i++)
            if(parent[i] == false){
                c++;
                ans = i;
            };
        return c == 1 ? ans : -1;
    }
};