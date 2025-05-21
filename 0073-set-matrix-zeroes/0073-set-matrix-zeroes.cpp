class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> cols(n, false), rows(m, false);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0) cols[i] = true, rows[j] = true;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(cols[i] || rows[j]) matrix[i][j] = 0;
            }
        }
    }
};