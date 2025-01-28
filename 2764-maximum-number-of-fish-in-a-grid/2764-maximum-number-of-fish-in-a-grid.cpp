class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j <0 || i == grid.size() || j == grid[0].size())
            return 0;
        if(grid[i][j] == 0)
            return 0;
        int ans = grid[i][j];
        grid[i][j] = 0;
        return  ans + solve(i +1, j, grid) +
                    solve(i -1, j, grid) +
                    solve(i, j+1, grid) + 
                    solve(i, j-1, grid);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, solve(i,j, grid));
            }
        }
        return ans;
    }
};