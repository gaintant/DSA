class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;
        int ans = 0;
        for(auto dominoe : dominoes){
            int l = min(dominoe[0], dominoe[1]);
            int h = max(dominoe[0], dominoe[1]);
            ans += mp[{l,h}]++;
        }
        return ans;
    }
};