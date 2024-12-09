class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parity(n, 0);
        vector<bool> ans;
        for(int i=1; i<n; i++){
            parity[i] = nums[i]%2 == nums[i-1]%2 ? parity[i-1] + 1: parity[i-1];
        }
        for(auto query : queries){
            ans.push_back(parity[query[0]] == parity[query[1]]);
        }
        return ans;
    }
};