class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> up(n+1, 0), down(n+1,0);
        long long ans = 1e10;
        for(int i=1; i<=n; i++){
            up[i] = up[i-1] + grid[0][i-1];
            down[i] = down[i-1] + grid[1][i-1];
        }
        for(int i=0; i<n; i++){
            ans = min(ans, max(up[n] - up[i+1], down[i]));
        }
        return ans;
    }
};