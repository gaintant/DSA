class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        set<string> st;
        for(auto c : dictionary)
            st.insert(c);
        vector<int> dp(n, INT_MAX);
        for(int i = n-1; i >= 0; i--){
            dp[i] = n-i;
            if(i < n-1) dp[i] = min(dp[i],1 + dp[i+1]);
            for(int j=0; j<=n-i;j++){
                if(st.find(s.substr(i,j)) != st.end()){
                    dp[i] = min(dp[i], (i+ j < n ? dp[i+j] : 0));
                    // cout<<dp[i]<<" "<<i<<endl;
                }
            }
        }
        return dp[0];
    }
};