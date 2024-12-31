class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = costs[0];
        for(int j = 0; j<n && days[j] < days[0] + 7; j++)
            dp[j] = min(dp[j], costs[1]);
        
        for(int j = 0;j<n &&  days[j] < days[0] + 30; j++)
            dp[j] = min(dp[j], costs[2]);
        
        for(int i=1; i<n; i++){
            dp[i] = min(dp[i], dp[i-1] + costs[0]);
            for(int j = i; j<n && days[j] < days[i] + 7; j++)
                dp[j] = min(dp[j], dp[i-1] + costs[1]);
            
            for(int j = i; j<n && days[j] < days[i] + 30; j++)
                dp[j] = min(dp[j],dp[i-1] + costs[2]);
        }
        return dp[n-1];
    }
};