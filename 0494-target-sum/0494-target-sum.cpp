class Solution {
public:
    int dp(int i, int t, vector<map<int, int>>& mps, vector<int> &nums){
        if(i == nums.size())
            return t == 0? 1 : 0;
        if(mps[i].find(t) != mps[i].end())
            return mps[i][t];
        return mps[i][t] = dp(i+1, t - nums[i], mps, nums) +
         dp(i+1, t + nums[i], mps, nums);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<map<int, int>> mps(nums.size());
        return dp(0, target, mps, nums);
    }
};