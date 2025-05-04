class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mp(100);
        int ans = 0, l , h;
        for(auto dominoe : dominoes){
            // l = min(dominoe[0], dominoe[1]);
            // h = max(dominoe[0], dominoe[1]);
            ans += mp[min(dominoe[0], dominoe[1])*10 + max(dominoe[0], dominoe[1])]++;
        }
        return ans;
    }
};