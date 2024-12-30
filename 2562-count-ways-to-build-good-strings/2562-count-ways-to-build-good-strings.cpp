class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1, 0);
        dp[0]++;
        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i=1; i<=high; i++){
            if(i-zero >= 0)
                dp[i] = dp[i-zero];
            if(i-one >= 0)
                dp[i] = (dp[i] + dp[i-one])%mod;
            if(i >= low)
                ans = (ans + dp[i])%mod;
            // cout<<dp[i]<<" "<<ans<<endl;
        }
        return ans;
    }
};