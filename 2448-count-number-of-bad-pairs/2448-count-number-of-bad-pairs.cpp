class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int, int> mp;
        long long n = nums.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += mp[nums[i] - i];
            mp[nums[i] - i]++;
        }
        return n*(n-1)/2 - ans;
    }
};