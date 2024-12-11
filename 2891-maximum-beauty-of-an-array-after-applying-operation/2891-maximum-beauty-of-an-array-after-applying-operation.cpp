class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j=1, n = nums.size();
        int ans = 1;
        for(int i=0; j<n;i++){
            while(j<n && nums[j] <= nums[i] +2*k)
                j++;
            ans = max(ans, j-i);
        }
        return ans;
    }
};