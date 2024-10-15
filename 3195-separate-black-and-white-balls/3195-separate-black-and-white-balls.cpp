class Solution {
public:
    long long minimumSteps(string s) {
        int reqPos = 0, n = s.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                ans += i - reqPos++;
            }
        }        
        return ans;
    }
};