class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++)
                if(isWater[i][j]) q.push({0,i,j});
        }

        while(!q.empty()){
            auto f = q.front();q.pop();
            int h = f[0], i = f[1], j = f[2];
            if(i<0 || j<0 || i ==n || j ==m || ans[i][j] != -1)
                continue;
            ans[i][j] = h;
            q.push({h+1, i+1, j});
            q.push({h+1, i-1, j});
            q.push({h+1, i, j+1});
            q.push({h+1, i, j-1});
        }
        return ans;
    }
};