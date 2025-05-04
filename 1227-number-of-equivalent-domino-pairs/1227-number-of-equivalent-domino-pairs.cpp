class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, int> mp;
        int ans = 0, l , h;
        for(auto dominoe : dominoes){
            l = min(dominoe[0], dominoe[1]);
            h = max(dominoe[0], dominoe[1]);
            ans += mp[l*10 + h]++;
        }
        return ans;
    }
};