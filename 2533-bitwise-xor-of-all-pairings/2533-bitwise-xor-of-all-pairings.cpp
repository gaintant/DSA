class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if(nums2.size()%2)for(auto num : nums1){
            ans =ans^num;
        }
        if(nums1.size()%2)for(auto num : nums2){
            ans =ans^num;
        }
        return ans;
    }
};