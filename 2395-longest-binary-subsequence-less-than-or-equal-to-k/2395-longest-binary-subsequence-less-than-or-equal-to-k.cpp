class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long pow = 1, ans =0;
        reverse(s.begin(), s.end());
        for(auto ele : s){
            // cout<<pow<<" "<<k<<endl;
            if(ele == '1' && k >= pow){
                k -= pow;
                ans++;
            }
            else if(ele == '0')ans++;
            if(pow <= k )pow *= 2;
        }
        return ans;
    }
};