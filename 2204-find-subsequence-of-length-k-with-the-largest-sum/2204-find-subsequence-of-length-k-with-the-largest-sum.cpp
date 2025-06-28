class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int g = 0;
            for(int j=0; j<i; j++)
                if(nums[j] >= nums[i]) g++;
            for(int j=i+1; j<n; j++)
                if(nums[j] > nums[i]) g++;
            if(g < k) ans.push_back(nums[i]);
        }
        return ans;
    }
};