class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n= grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<vector<int>> pq;
        pq.push({0,0,0});
        while(pq.top()[1] != n-1 || pq.top()[2] != m-1){
            auto top = pq.top();pq.pop();
            int c = top[0], i = top[1], j=top[2];
            // cout<<c<<" "<<i<<" "<<j<<endl;
            if(visited[i][j])
                continue;
            visited[i][j] = true;
            if(j != 0 && !visited[i][j-1])
                pq.push({(grid[i][j]==2 ? c : c-1),i,j-1 });
            if(j != m-1 && !visited[i][j+1])
                pq.push({(grid[i][j]==1 ? c : c-1),i,j+1 });
            if(i != 0 && !visited[i-1][j])
                pq.push({(grid[i][j]==4 ? c : c-1),i-1,j });
            if(i != n-1 && !visited[i+1][j])
                pq.push({(grid[i][j]==3 ? c : c-1),i+1,j });
        }
        return -pq.top()[0];
    }
};