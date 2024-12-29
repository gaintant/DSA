class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector<map<char, int>>& mps, string &target, vector<vector<int>>&dp ){
        int n = target.size(), m = mps.size();
        int dpi = (n-1)%2; 
        dp[dpi][m-1] = mps[m-1][target[n-1]];
        for(int i= m-2; i>=0; i--)
            dp[dpi][i] = (dp[dpi][i+1] + (long long)mps[i][target[n-1]])%mod;
        for(int i= n-2; i>=0; i--){
            int s = m - n + i;
            int ci = i%2, oi = (i+1)%2;
            dp[ci][s] = ((long long)mps[s][target[i]]*dp[oi][s+1])%mod;
            for(int j = s-1; j>=0; j--){
                long long c = mps[j][target[i]]; 
                dp[ci][j] = (dp[ci][j+1] + c*dp[oi][j+1])%mod;
            }
        }
        return dp[0][0];
    }
    int numWays(vector<string>& words, string target) {
        int n = target.size(), m = words[0].size();
        if(n > m)
            return 0;
        vector<vector<int>> dp(2, vector<int>(m, 0));
        vector<map<char, int>> mps(m);

        for(int i=0; i<m; i++)
            for(auto word : words)
                mps[i][word[i]]++; 

        return solve(mps, target, dp);
    }
};