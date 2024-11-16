class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int pre = 0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(i > 0 && nums[i] != nums[i-1] + 1)
                pre = i;
            if(i >= k -1){
                ans.push_back(i - pre + 1 >= k ? nums[i] : -1);
            }
        }
        return ans;
    }
};