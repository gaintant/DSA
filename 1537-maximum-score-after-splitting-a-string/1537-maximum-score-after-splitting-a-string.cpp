class Solution {
public:
    int maxScore(string s) {
        int one = 0, n = s.size()-1;
        int zero = 0, ans =0;
        for(auto ch : s)
            if(ch == '1') one++;
        for(int i=0; i<n; i++){
            if(s[i] == '1')
                one--;
            else
                zero++;
            ans = max(ans, one + zero);
        }
        return ans;
    }
};