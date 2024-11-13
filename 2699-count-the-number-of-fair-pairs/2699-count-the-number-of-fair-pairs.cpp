class Solution {
public:
    long long solve(vector<int>& nums, int k){
        int i = 0, j = nums.size() -1;
        long long ans = 0;
        while(j >= 0){
            while(i < j && nums[i] + nums[j] <= k){
                i++;
            }
            ans += min(i, j);
            // cout<<nums[i]<<" "<<nums[j]<<" "<<ans<<endl;
            j--;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return solve(nums, upper) - solve(nums, lower - 1);
    }
};