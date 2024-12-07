class Solution {
public:
    long long cal(vector<int> &nums, int mid){
        long long ans = 0;
        for(auto &num : nums){
            ans += (num-1) /mid;
        }
        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, h = -1;
        for(auto num : nums){
            h = max(h, num);
        }
        while(l < h){
            int mid = (l +h) >> 1;
            if(cal(nums, mid) <= maxOperations)
                h = mid;
            else
                l = mid + 1;
        }
        return h;
    }
};