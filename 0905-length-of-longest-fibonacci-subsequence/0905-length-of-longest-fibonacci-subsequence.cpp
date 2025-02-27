class Solution {
public:
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ans =0;
        vector<vector<int>> dp(n, vector<int> (n));
        map<int, int> mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(mp.find(arr[j] - arr[i]) != mp.end())
                    dp[i][j] = max(dp[i][j], 
                        max(2, dp[mp[arr[j] - arr[i]]][i]) + 1);
                    ans = max(ans, dp[i][j]);
            }
            mp[arr[i]] = i;
        }
        return ans;
    }
};