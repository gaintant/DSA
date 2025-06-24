class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int pre = -100000;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] == key){
                for(int j= max(0, max(pre + k+ 1, i-k)); j<=min(n-1, i+k); j++)
                    // cout<<i<<" "<<j<<endl;
                    ans.push_back(j);
                pre = i;    
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};