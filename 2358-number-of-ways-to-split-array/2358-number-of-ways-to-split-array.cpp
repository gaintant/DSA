class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n);
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
            preSum[i] = nums[i] + preSum[i-1];
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(2*preSum[i] >= preSum[n-1])
                ans++;
        }
        return ans;
    }
};