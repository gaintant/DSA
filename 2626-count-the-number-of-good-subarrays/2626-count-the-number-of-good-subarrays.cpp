class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0, j=0, matches =0, n = nums.size();
        long long ans = 0;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            matches += mp[nums[i]]++;
            while( matches - mp[nums[j]] + 1>= k){
                matches -= --mp[nums[j]];
                j++;
                // cout<<"in";
            }
            if(matches >= k)
                ans += j + 1; 
            // cout<<i<<" "<<j<<" "<<matches<<endl;
        }
        return ans;
    }
};