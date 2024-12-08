class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> rem(k, INT_MAX);
        rem[0] = 0;
        int n = nums.size();
        long long ans = -200000000000000;
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int r = (i+1)%k;
            if(i > k-2)
                ans = max(sum - rem[r], ans); 
            rem[r] = min(sum, rem[r]);
            // cout<<r<<" "<<rem[r]<<" "<<ans<<endl;
        }

        // sum = 0;
        // for(auto num : nums){
        //     sum += num;
        //     int r = (k + sum%k)%k;
        // }
        return ans;
    }
};