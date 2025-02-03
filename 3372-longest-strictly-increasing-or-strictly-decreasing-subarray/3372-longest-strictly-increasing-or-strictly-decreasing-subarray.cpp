class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int c= 1, ans =0, n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1])
                c++;
            else{
                ans = max(ans, c); 
                c =1;
            }    
        }
        ans = max(ans, c); c = 1;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1])
                c++;
            else{
                ans = max(ans, c); 
                c =1;
            }    
        }
        ans = max(ans, c); c = 1;
        return ans;
    }
};