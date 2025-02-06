class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, int>, int> mp;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            for(int j= i+1; j<n; j++){
                int g = gcd(nums[i], nums[j]);
                ans += mp[{nums[i]/g , nums[j]/g}];
            }
            for(int j=0; j<i; j++){
                int g = gcd(nums[i], nums[j]);
                mp[{nums[j]/g , nums[i]/g}]++;
            }
        }
        
        return 8*ans;
    }
};