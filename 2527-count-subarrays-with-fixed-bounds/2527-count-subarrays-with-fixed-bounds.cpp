class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int currMin = -2, currMax = -2;
        int startIndex= -1, n = nums.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                startIndex = i;
                continue;
            }
            if(nums[i] == minK) 
                currMin = i;
            if(nums[i] == maxK)
                currMax = i;
            if(currMin >= startIndex && currMax >= startIndex)
                ans += min(currMin, currMax) - startIndex ;
        }
        return ans;
    }
};