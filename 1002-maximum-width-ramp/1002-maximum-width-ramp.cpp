class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n);
        for(int i=0; i<n; i++)
            pos[i] = i;
        sort(pos.begin(), pos.end(), [&](int a, int b) {
            if(nums[a] == nums[b])
                return a < b;
            return nums[a] < nums[b];
            });
        int minVal = INT_MAX, ans = 0;
        for(auto i : pos){
            if(i > minVal)
                ans = max(i - minVal, ans);
            // else if(minVal < n && nums[minVal] == nums[i]){
            //     ans = max(i - minVal, ans);
            //     minVal =  i;
            // }
            else
                minVal =  i;
            // cout<<minVal<<" "<<i<<endl;
        }
        return ans;
    }
};